
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=1144
        ;;
    medium)
        N=8972
        ;;
    large)
        N=3000000
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

N=$N             
C=100  

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

