# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=500          # number of entries
        C=10           # range of entries
        ;;
    medium)
        N=5000000      # number of entries
        C=100          # range of entries
        ;;
    large)
        N=50000000     # number of entries
        C=100          # range of entries
        ;;
    xlarge)
        N=500000000     # number of entries
        C=100          # range of entries
        ;;
esac

echo $N
echo $C


# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   student      $N    $C
gen_fact_file     course        $N    $C
gen_fact_file     pre        $N    $C $C
gen_fact_file     take        $N    $C $C


