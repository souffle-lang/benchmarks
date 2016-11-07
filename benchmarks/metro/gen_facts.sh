
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=1000000          # number of entries
        C=100           # range of entries
        ;;
    medium)
        N=1000000      # number of entries
        C=100          # range of entries
        ;;
    large)
        N=50000000     # number of entries
        C=100         # range of entries
        ;;
    xlarge)
        N=500000000     # number of entries
        C=100     # range of entries
        ;;
esac

echo $N
echo $C

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   link      $N    $C $C $C

