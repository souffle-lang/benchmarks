# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

N=400000        # number of entries
C=100            # range of entries

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   Check        $N    $C $C $C $C $C $C  
gen_fact_file      In        $N    $C $C $C $C $C $C $C

