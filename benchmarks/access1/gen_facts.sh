
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=5000          # number of entries
        C=10           # range of entries
        ;;
    medium)
        N=20000000      # number of entries
        C=100          # range of entries
        ;;
    large)
        N=200000000     # number of entries
        C=100          # range of entries
        ;;
    xlarge)
        N=2000000000     # number of entries
        C=100          # range of entries
        ;;
esac

echo $N
echo $C

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   Trusted      $N    $C $C $C
gen_fact_file      BL        $N    $C $C $C
gen_fact_file      In        $N    $C $C $C

