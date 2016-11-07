#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $SIZE in
    small)
        LOW1=-10          # number of entries
        HIGH1=10           # range of entries
        LOW2=0          # number of entries
        HIGH2=10           # range of entries
        ;;
    medium)
        LOW1=-20          # number of entries
        HIGH1=20           # range of entries
        LOW2=0          # number of entries
        HIGH2=20           # range of entries        
        ;;
    large)
        LOW1=-30          # number of entries
        HIGH1=30           # range of entries
        LOW2=0          # number of entries
        HIGH2=30           # range of entries        
        ;;
    xlarge)
        LOW1=-10000          # number of entries
        HIGH1=10000           # range of entries
        LOW2=0          # number of entries
        HIGH2=10000           # range of entries     
        ;;
esac


# just seed fact files
mkdir -p facts
echo $LOW1 > facts/low1.facts
echo $LOW2 > facts/low2.facts
echo $HIGH1 > facts/high1.facts
echo $HIGH2 > facts/high2.facts

