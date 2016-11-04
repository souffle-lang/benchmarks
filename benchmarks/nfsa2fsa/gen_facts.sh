# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

S=10    # number of states
L=5     # number of letters
T=30    # number of transitions

# destinguish benchmark sizes
case $1 in
    small)
        S=500         
        L=10           
        T=30
        ;;
    medium)
        S=5000
        L=100           
        T=300
        ;;
    large)
        S=50000
        L=100
        T=300
        ;;
    xlarge)
        S=500000
        L=100
        T=300
        ;;
esac



# create fact files as needed
#             |   name   | |entries| |start| |end| |letter|
gen_fact_file         tr         $T      $S    $S       $L
