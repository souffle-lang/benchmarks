
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=500          # number of entries
        C=10           # range of entries
        ;;
    medium)
        N=5000      # number of entries
        C=10          # range of entries
        ;;
    large)
        N=50000     # number of entries
        C=100          # range of entries
        ;;
    xlarge)
        N=50000     # number of entries
        C=100          # range of entries
        ;;
esac

echo $N
echo $C

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   num_letters      $N    $C
gen_fact_file      a        $N    $C $C $C
gen_fact_file      idx        $N    $C $C

