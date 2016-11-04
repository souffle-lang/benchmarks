# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $1 in
    small)
        N=5000          # number of entries
        C=10           # range of entries
        ;;
    medium)
        N=500000      # number of entries
        C=100          # range of entries
        ;;
    large)
        N=5000000     # number of entries
        C=100          # range of entries
        ;;
    xlarge)
        N=50000000     # number of entries
        C=100          # range of entries
        ;;
esac

echo $N
echo $C

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   AssignAlloc  $N    $C $C
gen_fact_file   PrimitiveAssign  $N  $C $C
gen_fact_file      Load      $N    $C $C $C
gen_fact_file      Store     $N    $C $C $C

