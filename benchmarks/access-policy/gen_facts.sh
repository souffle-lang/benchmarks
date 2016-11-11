
# include general utilities
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=1144
        ;;
    medium)
        N=8972
        ;;
    large)
        N=24658
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac

N=$N             
C=100  

# create fact files as needed
#             | name | |entries| |       ranges        |

gen_fact_file employee $N $C $C $C $C $C $C $C

gen_fact_file inslogtable $N $C $C $C

gen_fact_file insurance $N $C


