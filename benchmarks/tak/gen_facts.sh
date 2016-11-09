#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $SIZE in
    small)
        N=9
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


LOW1=-$N         # number of entries
HIGH1=$N         # range of entries
LOW2=0           # number of entries
HIGH2=$N         # range of entries


# just seed fact files
mkdir -p facts
echo $LOW1 > facts/low1.facts
echo $LOW2 > facts/low2.facts
echo $HIGH1 > facts/high1.facts
echo $HIGH2 > facts/high2.facts

