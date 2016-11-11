
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=232974
        ;;
    medium)
        N=32789960
        ;;
    large)
        N=323295156
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
gen_fact_file   Trusted      $N    $C $C $C
gen_fact_file      BL        $N    $C $C $C
gen_fact_file      In        $N    $C $C $C

