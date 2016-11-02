
# a function to generate random fact files
gen_fact_file() {
    src_dir=`dirname $BASH_SOURCE[0]`
    ruby $src_dir/random_fact_generator.rb $@ > $1.tuples
}

