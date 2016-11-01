# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

N=2000    # number of connections
C=500     # number of entities

# create fact files as needed
#             | name | |entries| |range_start|  |range_end|
gen_fact_file   SNet         $N            $C           $C 
gen_fact_file  Train         $N            $C           $C
gen_fact_file   Ship         $N            $C           $C
gen_fact_file    Cap         $N            $C           $C
