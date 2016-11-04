# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
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
