
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=47
        ;;
    medium)
        N=2750
        ;;
    large)
        N=1237250062076563423232
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

N=`expr $N \* 1000`
C=`expr $N \* 500`

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   father      $N    $C $C
gen_fact_file   mother      $N    $C $C

