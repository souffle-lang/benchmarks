
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=9     
        C=9         
        N1=2
        N2=2
        C2=4
        ;;
    medium)
        N=49
        C=49        
        N1=3
        N2=3
        C2=9
        ;;
    large)
        N=121
        C=121       
        N1=6
        N2=6
        C2=36
        ;;
    xlarge)
        N=841
        C=841       
        N1=100
        N2=100
        C2=1000
        ;;
esac

echo $N
echo $C

# create fact files as needed
#             | name | |entries| |       ranges        |
gen_fact_file   cell      $N    $C
gen_fact_file      player        $N1    $C
gen_fact_file      other        $N2    $C2 $C2

