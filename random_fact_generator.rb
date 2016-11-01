
# --- a script to generate random fact files ---

# get some parameters from the command line
if (ARGV.length < 3 || ARGV.length > 4) then
    puts "Usage: random_fact_generator.rb <seed> <num_columns> <num_rows> [max_value]"
    exit 1
end

seed = ARGV[0].to_i(36)
num_columns = ARGV[1].to_i()
num_entries = ARGV[2].to_i()
max_value = (ARGV.length == 4) ? ARGV[3].to_i : [num_columns,num_entries].min/10

if (max_value < 1) then
    max_value = 2
end

# seed the random number generator (to get reproducable results)
srand (seed)

# data generation
num_entries.times do |i|

    # print a record
    num_columns.times do |j|

        # print a value
        print rand(max_value)

        # add a tap
        print "\t" unless j+1 == num_columns
    end

    # finish with a new-line
    puts 
end


