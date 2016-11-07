# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        S=500         
        L=10           
        T=30
        ;;
    medium)
        S=5000
        L=100           
        T=300
        ;;
    large)
        S=50000
        L=100
        T=300
        ;;
    xlarge)
        S=500000
        L=100
        T=300
        ;;
    custom)
        N=${N:=10}
        echo "Custom problem size $N"
        S=$N                        # number of states
        L=`expr $N / 10`
        T=`expr $S \* $L`
        ;;
esac

# small size: N=10
# medium: N=13


# create fact files as needed
#             |   name   | |entries| |start| |end| |letter|
gen_fact_file         tr         $T      $S    $S       $L
