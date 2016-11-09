
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=4108
        ;;
    medium)
        N=1000000
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


N1=1
SZ=$N
C=100
N=`expr $N \* 10`


# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   parameters      $N1    $SZ
gen_fact_file   values          $SZ    $SZ $C
gen_fact_file   transition      $N     $C $C $C $C
gen_fact_file   terminate       $N     $C

