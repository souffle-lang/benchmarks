# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
	N=10
        ;;
    medium)
	N=13
        ;;
    large)
	N=14
        ;;
    xlarge)
	N=15
        ;;
    custom)
        N=${N:=10}
        echo "Custom problem size $N"     
        ;;
esac

S=$N                        # number of states
L=`expr $N / 10`
T=`expr $S \* $L`


# create fact files as needed
#             |   name   | |entries| |start| |end| |letter|
gen_fact_file         tr         $T      $S    $S       $L
