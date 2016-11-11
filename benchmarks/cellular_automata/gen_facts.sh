
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=168
        ;;
    medium)
        N=669
        ;;
    large)
        N=1320
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac


N=$N        # number of elements in input array
T=$N        # number of time steps to be processed


# create fact files as needed
mkdir -p facts
echo $N > facts/parameters.facts
echo $T > facts/terminate.facts

B=`expr $N - 1`
echo -e "0\t1" > facts/values.facts
for i in `seq 1 $B` ; do
    echo -e "$i\t1" >> facts/values.facts
done

