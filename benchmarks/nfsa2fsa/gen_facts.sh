# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

S=10    # number of states
L=5     # number of letters
T=30    # number of transitions

# create fact files as needed
#             |   name   | |entries| |start| |end| |letter|
gen_fact_file         tr         $T      $S    $S       $L
