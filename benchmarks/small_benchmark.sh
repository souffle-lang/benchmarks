root="/home/rdow6615"
benchdir="$root/benchmarks/benchmarks"
programs=(tc topological_ordering pointsto)
instance=$1
  
cd $benchdir

for program in ${programs[@]}; do
  $program/gen_facts.sh > /dev/null
  ./timer.sh $program/$program.dl -I $instance -F facts
done
