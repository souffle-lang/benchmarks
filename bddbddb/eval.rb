require 'find'
require 'fileutils'


# ------------------- Configuration ---------------------------

souffle_root = "~/coding/c++/souffle"
souffle_exec  = "#{souffle_root}/build_release/src/souffle"

bddbddb_exec = "java -jar ~/libs/bddbddb-latest/bddbddb-full.jar"

benchmark_dir = "../benchmarks"
working_dir = "./evaluation"

timeout="10s"

if ENV["SIZE"] == "small" then
    timeout="3s"
end

if ENV["SIZE"] == "medium" then
    timeout="180s"
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
	attr_accessor :run_time, :memory_usage, :exit_status
	def print_out 
		print self.run_time
		print ","
		print self.memory_usage
        print ","
        print self.exit_status
	end
end

class Entry 
	attr_accessor :name
	attr_accessor :data

	def print_out
		print self.name
		print ", "
		self.data.print_out
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
end

def eval_case(timeout,cmd)
	result = Measurement.new

	# run evaluation
    puts "\trunning evaluation ..."
	stats = `/usr/bin/time -v timeout #{timeout} #{cmd} 2>&1`

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
    facts = "./facts"
    fact_generator = File.expand_path("gen_facts.sh",File.dirname(dlFile))

	result = Entry.new
	result.name = name;

    # create facts
    puts "Preparing test case " + name + " (#{i}/#{num_cases}).."
    `/bin/bash #{fact_generator}`

    # adapt facts for bddbddb
    if File.exists?(facts) then
        Find.find(facts) do |path|
            next unless path =~ /.*\.facts$/ 
            name = File.basename(path,".facts")
            File.rename("#{path}","#{name}.tuples")
        end
    end

    # create bddbddb input file
    puts "Creating bddbddb specification .."
    puts `#{souffle_exec} #{dlFile} -b #{name}.dl`

    # run evaluations
	puts "Running test case " + name + " (#{i}/#{num_cases}).."
    result.data = eval_case(timeout,"#{bddbddb_exec} #{name}.dl")

	# record result
	data << result

    # cleanup
    `rm -r #{facts}`
    `rm *.tuples`

	print_result(data)

	puts ""

end 
