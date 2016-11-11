# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=216
        ;;
    medium)
        N=899
        ;;
    large)
        N=1788
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

C=$N                    # number of stations
N=`expr $C \* 4`        # 4 connections on average


# create fact files as needed
#             | name | |entries| |range_start|  |range_end|
gen_fact_file   SNet         $N            $C           $C 
gen_fact_file  Train         $N            $C           $C
gen_fact_file   Ship         $N            $C           $C
gen_fact_file    Cap         $N            $C           $C
