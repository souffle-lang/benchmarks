require 'find'
require 'fileutils'


# ------------------- Configuration ---------------------------

souffle_root = "~/coding/c++/souffle"
souffle_exec  = "#{souffle_root}/build_release/src/souffle"

benchmark_dir = "../benchmarks"
working_dir = "./evaluation"

# short
@timeout=1.0

# medium
@timeout=60.0

# large
#@timeout=600.0

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


def evaluate(fact_generator, execname, size) 

    # generate the facts
    puts "\tgenerating facts of size N=#{size} ..."
    ENV["SIZE"] = "custom"
    ENV["N"] = "#{size}"
    `/bin/bash #{fact_generator}`
    ENV.delete("N");
    ENV.delete("SIZE");

    # run evaluation
    puts "\trunning #{execname}..."
	stats = `/usr/bin/time -v timeout #{@timeout * 3.0} ./#{execname} 2>&1`

	puts stats unless !@debug

    # check the exit status
	e = stats.match(/Exit status.*: ([\d]+)$/).captures[0]

    # if timeout, return -1
    if e.to_i == 0 

	    # extract computation time
	    m, s, h = stats.match(/Elapsed.*: ([\d]+):(\d\d).(\d\d)$/i).captures
	    t = ((m.to_i) *60 + (s.to_i))*1000 + (h.to_i)*10

        puts "\t\tN=#{size} t=#{t}"
        return t
 
    end

    puts "\t\tN=#{size} t= -timeout-"
    return -1

end


class Setup
	attr_accessor :name, :size
	def print_out 
		print self.name
		print ","
		print self.size
	end
end

def print_result(data)
    data.each do |entry|
	    entry.print_out
	    puts ""
	end
end

# the data to be collected
data = []

# create the wworking directory
`mkdir -p #{working_dir}`

# change to the working directory
Dir.chdir working_dir

num_cases = dl_files.length
puts "Calibrating #{num_cases} benchmarks ..."

i = 0

# process one file after another
dl_files.each do |dlFile|

	result = Setup.new

    i = i + 1
	name = File.basename(dlFile,".dl")

    facts = "./facts"
    fact_generator = File.expand_path("gen_facts.sh",File.dirname(dlFile))

	exec = "#{name}"

    # compile test case
    puts "Compiling benchmark " + name + " (#{i}/#{num_cases}).."
    ENV["SOUFFLE_USE_NAIVE_INDEX"] = "1"
    `#{souffle_exec} #{dlFile} -F #{facts} -o #{exec}`
    ENV.delete("SOUFFLE_USE_NAIVE_INDEX");

    # the time we seek to be achived
    target_time = (@timeout * 1000)

    # start growing problem size until exceeding the time limit
    n = 1
    old_t = 0
    t = evaluate(fact_generator,exec,n)
    while t >= 0 && t < target_time do
        n = n * 2
        old_t = t
        t = evaluate(fact_generator,exec,n)
    end


    # now narrow in using interpolation search
    l = n / 2
    h = n

    low_t = old_t
    hig_t = (t < 0) ? 3*target_time : t


    while l != h do
        m = (l + (((target_time - low_t)*(h-l)) / (hig_t - low_t))).to_i;

        if (h - l) < (m / 100) then
            h = m;
            l = m;
            break;
        end

        t = evaluate(fact_generator,exec,m)

        if (t-target_time).abs < 0.01 * target_time 
            # we can stop here
            h = m
            l = m
        else 
		    if t < 0 || t > target_time
		        h = m
                hig_t = t
		    else
		        h = m if l == m
		        l = m
                low_t = t
		    end
	    end
    end

    # take the result
    n = l

    # pick this as the result
    puts "Problem size: N=#{n}"

    result.name = name
    result.size = n
    
	# record result
	data << result

    # cleanup
    `rm -r #{facts}`

	print_result(data)

	puts ""

end 
