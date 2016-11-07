
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=400         # number of objects
        ;;
    medium)
        N=800         # number of objects
        ;;
    large)
        N=4000        # number of objects
        ;;
    xlarge)
        N=10000       # number of objects
        ;;
esac



# create fact files as needed
#             | name | |    entries     |  | ranges |
gen_fact_file   orbits   `expr 2 \* $N`       $N  $N
