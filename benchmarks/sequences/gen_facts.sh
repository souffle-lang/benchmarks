
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=652
        ;;
    medium)
        N=1000000
        ;;
    large)
        N=3000000
        ;;
    xlarge)
        N=50000000
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
