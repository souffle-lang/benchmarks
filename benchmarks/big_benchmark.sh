## You will need to change this according to ur username
## and wherever you have doop installed
root="/home/rdow6615"
setting="2-object-sensitive+heap"
benchdir="$root/summer2019/doop/out/$setting"
programs=(antlr bloat jython chart eclipse fop hsqldb pmd xalan)
instance=$1
  
cd $benchdir

for program in ${programs[@]}; do
  folder=souffle-$program
  $root/benchmarks/benchmarks/timer.sh $folder/$setting.dl -I $instance -F $folder/facts
done
