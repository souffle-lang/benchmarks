#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $SIZE in
    small)
        LOW=0          # number of entries
        HIGH=300    # range of entries
        ;;
    medium)
        LOW=0          # number of entries
        HIGH=3000           # range of entries
        ;;
    large)
        LOW=0          # number of entries
        HIGH=30000           # range of entries
        ;;
    xlarge)
        LOW=0          # number of entries
        HIGH=300000           # range of entries
        ;;
esac

# just seed fact files
mkdir -p facts
echo $LOW > facts/low.facts
echo $HIGH > facts/high.facts

