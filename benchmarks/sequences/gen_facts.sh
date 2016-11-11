
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=652
        ;;
    medium)
        N=4602
        ;;
    large)
        N=11571
        ;;
    xlarge)
        N=5000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac


# create fact files as needed
mkdir -p facts
echo $N > facts/num_letters.facts
seq 1 $N > facts/a.facts
