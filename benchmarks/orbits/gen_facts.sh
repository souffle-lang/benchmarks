
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=437
        ;;
    medium)
        N=1717
        ;;
    large)
        N=3481
        ;;
    xlarge)
        N=10000
        ;;
    custom)
        N=${N:=400}
        echo "Custom problem size $N"     
        ;;
esac


# create fact files as needed
#             | name | |    entries     |  | ranges |
gen_fact_file   orbits   `expr 2 \* $N`       $N  $N
