
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=390
        ;;
    medium)
        N=1576
        ;;
    large)
        N=3166
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

C=$N
E=`expr $C \* 10`    # each node has on average 10 neighbors

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   base      $E    $C $C

