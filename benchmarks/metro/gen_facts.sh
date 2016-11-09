
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=128
        ;;
    medium)
        N=4860
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

S=$N
N=`expr $N \* 1000`   # numer of stations
C=`expr $N \* 3`      # 3 connections average per station

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   link      $C             $N $N 
gen_fact_file   start     $S             $N


