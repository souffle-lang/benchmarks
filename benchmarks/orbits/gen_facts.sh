
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=400
        ;;
    medium)
        N=800
        ;;
    large)
        N=4000
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
