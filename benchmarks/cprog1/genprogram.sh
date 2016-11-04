#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $1 in
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

PROG=".decl loop(line: number, x:number, y:number, z:number)

.decl Res() output

loop(0, ${LOW}, ${MED},${HIGH}).
loop(1, x, y, z)   :- loop(0, x, y, z). 
loop(1, x+1, y, z) :- loop(1, x, y, _), loop(0, _, _, z), x < y. 

loop(2, x, y, z) :- loop(1, x, y, z), x >= y.
loop(2, x, y+1, z) :- loop(2, _, y, z), loop(1, x, _, _),  y < z. 

loop(3, x, y, z) :- loop(2, x, y, z), y >= z.
Res() :- loop(3, _, y, _), y = ${HIGH}."

echo $PROG > ./cprog1.dl


