
# --- a script to generate random fact files ---

# get some parameters from the command line
if (ARGV.length < 3 ) then
    puts "Usage: random_fact_generator.rb <seed> <num_rows> [max_value_c1, max_value_c2, ...]"
    exit 1
end

# read sead and number of entries
seed = ARGV[0].to_i(36)
num_rows = ARGV[1].to_i()

# read the value distribution
dist=[]
(ARGV.length-2).times do |i|
    dist << ARGV[i+2].to_i
end

# seed the random number generator (to get reproducable results)
srand (seed)

# data generation
num_rows.times do |i|

    # print a record
    dist.length.times do |i|

        # print a value
        print rand(dist[i])

        print "\t" unless i+1 == dist.length
    end

    # finish with a new-line
    puts 
end


