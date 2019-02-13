name=(current rewrite_templated before_rewrite_templated before_abdul before_trie)
sha=(HEAD a2d4ecef 76881a09 0225c49b 5fd84e72 77401071)
root="/home/rdow6615"
benchdir="$root/benchmarks/benchmarks"
programs=(tc topological_ordering pointsto)

for name in ${name[@]}; do
  instance="$root/$name/src/souffle"
  
  cd $benchdir
  
  for program in ${programs[@]}; do
      $program/gen_facts.sh > /dev/null
  
      printf "$name\t"
      ./profile.sh $program/$program.dl -I $instance -F facts 

  done
done
