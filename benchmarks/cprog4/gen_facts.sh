#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $SIZE in
    small)
        LOW=0          # number of entries
        MED=150           # range of entries
        HIGH=300           # range of entries
        ;;
    medium)
        LOW=0          # number of entries
        MED=1000           # range of entries
        HIGH=2000           # range of entries
        ;;
    large)
        LOW=0          # number of entries
        MED=2500           # range of entries
        HIGH=5000           # range of entries
        ;;
    xlarge)
        LOW=0          # number of entries
        MED=5000           # range of entries
        HIGH=10000           # range of entries
        ;;
esac

# just seed fact files
mkdir -p facts
echo $LOW > facts/low.facts
echo $MED > facts/med.facts
echo $HIGH > facts/high.facts


