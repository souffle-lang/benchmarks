# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=200          # number of entries
        C=50           # range of entries
        ;;
    medium)
        N=2000      # number of entries
        C=500          # range of entries
        ;;
    large)
        N=20000     # number of entries
        C=500          # range of entries
        ;;
    xlarge)
        N=200000     # number of entries
        C=500          # range of entries
        ;;
esac

# create fact files as needed
#             | name | |entries| |range_start|  |range_end|
gen_fact_file   SNet         $N            $C           $C 
gen_fact_file  Train         $N            $C           $C
gen_fact_file   Ship         $N            $C           $C
gen_fact_file    Cap         $N            $C           $C
