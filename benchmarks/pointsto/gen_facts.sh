# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=1756
        ;;
    medium)
        N=7070 
        ;;
    large)
        N=13874 
        ;;
    xlarge)
        N=4000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

N=$N                        # number of instructions of each type
O=`expr $N / 10`            # number of objects 
V=`expr $N / 4`             # number of variables
F=10                        # number of fields


# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   AssignAlloc  $N    $V $O
gen_fact_file   PrimitiveAssign  $N  $V $V
gen_fact_file      Load      $N    $V $V $F
gen_fact_file      Store     $N    $V $V $F

