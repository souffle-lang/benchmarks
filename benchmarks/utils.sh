
# a function to generate random fact files
gen_fact_file() {
    mkdir -p facts
    src_dir=`dirname $BASH_SOURCE[0]`
    ruby $src_dir/random_fact_generator.rb $@ > facts/$1.facts
}

# set default benchmark size to small
SIZE=${SIZE:=small}


