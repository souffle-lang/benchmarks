
# a function to generate random fact files

gen_fact_file() {
    mkdir -p facts
    ruby ../random_fact_generator.rb $2 $3 $4 > facts/$1.facts
}

