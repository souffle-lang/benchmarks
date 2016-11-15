require 'find'
require 'fileutils'


# ------------------- Configuration ---------------------------

souffle_root = "~/coding/c++/souffle"
souffle_exec  = "#{souffle_root}/build_release/src/souffle"

benchmark_dir = "../benchmarks"
benchmark_dir = "/home/herbert/coding/c++/souffle/tests/evaluation"
working_dir = "./evaluation"


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
	attr_accessor :compile_time, :num_indexes
	def print_out 
		print self.compile_time
        print ","
        print self.num_indexes
	end
end

class Entry 
	attr_accessor :name, :num_rules
	attr_accessor :auto, :naive, :scan

	def print_out
		print self.name
		print ", "
		print self.num_rules
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
end

def eval_case(cmd,execname)
	result = Measurement.new

	# run compiler
    puts "\tcompiling #{execname}..."
	start = Time.now
	out = `#{cmd} -g #{execname}`
	result.compile_time = Time.now - start

    # print compiler log
    puts out unless !@debug
	
    # get the number of indexes
    result.num_indexes = `grep -o "ram::index<" #{execname}.cpp | wc -l`.to_i()

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

    # count the number of rules
    `#{souffle_exec} #{dlFile} -b #{name}_expanded.dl`

    # get the number of rules
    result.num_rules = `grep -o ":-" #{name}_expanded.dl | wc -l`.to_i()


	auto_exec = "#{name}_auto"
	naive_exec = "#{name}_naive"
    scan_exec = "#{name}_scan"

    # run evaluations
	puts "Running test case " + name + " (#{i}/#{num_cases}).."
	base_cmd = "#{souffle_exec} #{dlFile} -F #{facts}"

	# evaluate option with auto_index
	result.auto = eval_case("#{base_cmd}",auto_exec)
	
	# evaluate option with naive_index
    ENV["SOUFFLE_USE_NAIVE_INDEX"] = "1"
	result.naive = eval_case("#{base_cmd}", naive_exec)
    ENV.delete("SOUFFLE_USE_NAIVE_INDEX");
	
    # evaluate option with no index
    ENV["SOUFFLE_USE_NO_INDEX"] = "1"
	result.scan = eval_case("#{base_cmd}", scan_exec)
    ENV.delete("SOUFFLE_USE_NO_INDEX");

	# record result
	data << result

	print_result(data)

	puts ""

end 
