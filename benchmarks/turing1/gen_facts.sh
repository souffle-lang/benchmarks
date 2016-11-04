# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=5
        S=5          # number of entries
        A=3           # range of entries
        L=2           # range of entries
        ;;
    medium)
        N=50
        S=50          # number of entries
        A=3           # range of entries
        L=2           # range of entries
        ;;
    large)
        N=500
        S=500          # number of entries
        A=30           # range of entries
        L=2           # range of entries
        ;;
    xlarge)
        N=5000
        S=5000          # number of entries
        A=30           # range of entries
        L=2           # range of entries
        ;;
esac


# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   Transition   $N  $S $S $A $A $L

