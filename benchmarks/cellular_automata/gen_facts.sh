
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N1=1
	SZ=500
        C=1000
	N=50000
        ;;
    medium)
        N1=1
	SZ=500
        C=100	
	N=5000
	;;
    large)
        N1=1
	SZ=5000
        C=100	
	N=50000
	;;
    xlarge)
        N1=1
	SZ=5000
        C=100	
	N=50000
esac

echo $N1
echo $SZ
echo $C
echo $N

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   parameters      $N1    $SZ
gen_fact_file   values          $SZ    $SZ $C
gen_fact_file   transition      $N     $C $C $C $C
gen_fact_file   terminate       $N     $C

