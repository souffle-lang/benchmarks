# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=5
        ;;
    medium)
        N=50
        ;;
    large)
        N=500
        ;;
    xlarge)
        N=5000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac


S=$N
A=15
S=2

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   Transition   $N  $S $S $A $A $L

