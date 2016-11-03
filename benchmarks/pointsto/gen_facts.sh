# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

N=500000        # number of entries
C=100            # range of entries

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   AssignAlloc  $N    $C $C
gen_fact_file   PrimitiveAssign  $N  $C $C
gen_fact_file      Load      $N    $C $C $C
gen_fact_file      Store     $N    $C $C $C

