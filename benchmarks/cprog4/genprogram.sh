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

PROG=".decl loop(i:number, x:number, y:number, z:number)
.decl R() output

loop(0, 0, 0, 0).

loop(1, ${HIGH}, y, z) :- loop(0, _, y, z).
loop(2, x, y, ${MED}) :- loop(1, x, y, _).
loop(3, x, ${LOW}, z) :- loop(0, _, _, z), loop(1, x, _, _). 
loop(7, x, y, z)  :- loop(3, x, y, z), x <= z, z <= y.

loop(4, x, y, z)  :- loop(3, x, y, z), x > z.
loop(4, x, y, z)  :- loop(3, x, y, z), z > y.

loop(5, x, y, z+1)  :- loop(4, x, y, z), x > z.
loop(5, x, y+1, z)  :- loop(4, x, y, z), z > y, z <= z.

loop(3, x, y, z) :- loop(5, x, y, z).

R() :- loop(7, x, y, z),  x = z, y = z.



"

echo $PROG > ./cprog4.dl


