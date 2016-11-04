
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $1 in
    small)
        N=500          # number of entries
        C=10           # range of entries
        ;;
    medium)
        N=5000      # number of entries
        C=100          # range of entries
        ;;
    large)
        N=50000     # number of entries
        C=100          # range of entries
        ;;
    xlarge)
        N=500000     # number of entries
        C=100          # range of entries
        ;;
esac

echo $N
echo $C

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file view_bank1 $N  $N $C  $C
gen_fact_file view_bank2 $N  $N $C  $C

gen_fact_file employee $N $C $C $C $C $C $C $C

gen_fact_file inslogtable $N $C $C $C

gen_fact_file insurance $N $C

gen_fact_file bank1 $N $C $C
gen_fact_file bank2 $N $C $C

gen_fact_file inscwPriv $N $C $C $C
gen_fact_file delcwPriv $N $C $C $C
gen_fact_file cwPriv $N $C $C $C

