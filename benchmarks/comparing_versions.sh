# lets use tc, pointsto, topological_ordering

programs=(tc pointsto topological_ordering)
instances=(current rewrite_templated before_rewrite_templated before_abdul before_trie beginning)

for program in ${programs[@]}; do
  $program/gen_facts.sh
  for instance in ${instances[@]}; do
    printf "$instance,"
    ./timer.sh $program/$program.dl -F facts -I /home/rdow6615/$instance/src/souffle
  done
done
