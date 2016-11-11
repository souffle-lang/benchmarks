# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh
# destinguish benchmark sizes

# destinguish benchmark sizes
case $SIZE in
    small)
        N=143457
        ;;
    medium)
        N=4312274
        ;;
    large)
        N=28384892
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
gen_fact_file   In      $N    $C $C $C $C $C $C $C
gen_fact_file     Tbl        $N    $C $C $C $C

