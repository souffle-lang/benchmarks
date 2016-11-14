require 'find'
require 'fileutils'


# ------------------- Configuration ---------------------------

souffle_root = "~/coding/c++/souffle"
souffle_exec  = "#{souffle_root}/build_release/src/souffle"

benchmark_dir = "../benchmarks"
working_dir = "./evaluation"

timeout="10s"

if ENV["SIZE"] == "small" then
    timeout="3s"
end

if ENV["SIZE"] == "medium" then
    timeout="180s"
end

if ENV["SIZE"] == "large" then
    timeout="1800s"
end

@debug = false

# -------------------------------------------------------------


# find all input files
dl_files = []
Find.find(benchmark_dir) do |path|
	dl_files << File.absolute_path(path) if path =~ /.*\.dl$/
end

# filter out user-selected test cases
cases = ARGV
if cases.length > 0 then
    all_dl_files = dl_files
    dl_files = []
    all_dl_files.each do |dlFile|
        name = File.basename(dlFile,".dl")
        dl_files << dlFile unless !cases.include?(name)
    end
end


class Measurement
	attr_accessor :compile_time, :run_time, :memory_usage, :num_indexes, :exit_status
	def print_out 
		print self.compile_time
		print ","
		print self.run_time
		print ","
		print self.memory_usage
        print ","
        print self.num_indexes
        print ","
        print self.exit_status
	end
end

class Entry 
	attr_accessor :name
	attr_accessor :auto, :naive, :scan
	attr_accessor :equal

	def print_out
		print self.name
		print ","
		print self.equal
		print ", "
		self.auto.print_out
		print ", "
		self.naive.print_out
		print ", "
		self.scan.print_out
	end
end

# the data to be collected
data = []

def print_result(data)
	puts ""
	puts "---- Results ----"
	data.each do |entry|
		entry.print_out
		puts ""
	end
    puts ""
	puts "---- Filtered ----"
	data.each do |entry|
        if !entry.equal then
		    entry.print_out
		    puts ""
        end
	end
end

def eval_case(timeout,cmd,execname)
	result = Measurement.new

	# run compiler
    puts "\tcompiling #{execname}..."
	start = Time.now
	out = `#{cmd} -o #{execname}`
	result.compile_time = Time.now - start

    # print compiler log
    puts out unless !@debug
	
    # get the number of indexes
    result.num_indexes = `grep -o "ram::index<" #{execname}.cpp | wc -l`.to_i()

	# run evaluation
    puts "\trunning #{execname}..."
	stats = `/usr/bin/time -v timeout #{timeout} ./#{execname} 2>&1`

	puts stats unless !@debug

    # check the exit status
	e = stats.match(/Exit status.*: ([\d]+)$/).captures[0]
    result.exit_status = e.to_i

	# extract computation time
	m, s, h = stats.match(/Elapsed.*: ([\d]+):(\d\d).(\d\d)$/i).captures
	result.run_time = ((m.to_i) *60 + (s.to_i))*1000 + (h.to_i)*10

	# extract memory usage
	m = stats.match(/Maximum resident.*: ([\d]+)$/).captures[0]
	result.memory_usage = m.to_i;

    # print some result
    if (result.exit_status == 124) then
        puts "\t\t -timeout-\n"
    else
        puts "\t\tt = #{result.run_time}ms, m = #{result.memory_usage}KB"
    end

    # done
	return result
end


# create the wworking directory
`mkdir -p #{working_dir}`

# change to the working directory
Dir.chdir working_dir

num_cases = dl_files.length
puts "Running #{num_cases} test cases ..."

i = 0

# process one file after another
dl_files.each do |dlFile|

    i = i + 1
	name = File.basename(dlFile,".dl")
	# facts = File.expand_path("facts",File.dirname(dlFile))
    facts = "./facts"
    fact_generator = File.expand_path("gen_facts.sh",File.dirname(dlFile))

	result = Entry.new
	result.name = name;

	auto_exec = "#{name}_auto"
	naive_exec = "#{name}_naive"
    scan_exec = "#{name}_scan"

    # create facts
    puts "Preparing test case " + name + " (#{i}/#{num_cases}).."
    `/bin/bash #{fact_generator}`

    # run evaluations
	puts "Running test case " + name + " (#{i}/#{num_cases}).."
	base_cmd = "#{souffle_exec} #{dlFile} -F #{facts}"

	# evaluate option with auto_index
	result.auto = eval_case(timeout,"#{base_cmd}",auto_exec)
	
	# evaluate option with naive_index
    ENV["SOUFFLE_USE_NAIVE_INDEX"] = "1"
	result.naive = eval_case(timeout,"#{base_cmd}", naive_exec)
    ENV.delete("SOUFFLE_USE_NAIVE_INDEX");
	
    # evaluate option with no index
    ENV["SOUFFLE_USE_NO_INDEX"] = "1"
	result.scan = eval_case(timeout,"#{base_cmd}", scan_exec)
    ENV.delete("SOUFFLE_USE_NO_INDEX");
	
	# record whether auto-index is actually different from the naive index
	result.equal = `diff #{auto_exec}.cpp #{naive_exec}.cpp | grep "Relation"` == ""

	# record result
	data << result

    # cleanup
    `rm -r #{facts}`

	print_result(data)

	puts ""

end 
