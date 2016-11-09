#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

# destinguish benchmark sizes
case $SIZE in
    small)
        N=1188
        ;;
    medium)
        N=1000000
        ;;
    large)
        N=3000000
        ;;
    xlarge)
        N=50000000
        ;;
    custom)
        N=${N:=1000}
        echo "Custom problem size $N"     
        ;;
esac
 
N=`expr $N \* 1000`

# just seed fact files
mkdir -p facts
echo 0 > facts/low.facts
echo $N > facts/high.facts

