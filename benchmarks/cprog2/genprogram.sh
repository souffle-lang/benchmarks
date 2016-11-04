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

PROG=".decl loop(i:number, x:number, y:number, z:number) output
.decl Res() output

loop(0, 0, 0, 0).
loop(1, x, ${LOW}, z) :- loop(0, x, _, z).
loop(2, x, y, ${MED}) :- loop(1, x, y, _).
loop(3, ${HIGH}, y, z) :- loop(2, _, y, _), loop(1, _, _, z).
loop(4, x, y, z) :- loop(2, _, y, z), loop(3, x, y, z), x > z.
loop(4, x, y, z+1) :- loop(4, x, y, z), x > z.
loop(5, x, y, z) :- loop(4, x, y, z), x <= z.
loop(5, x, y+1, z) :- loop(5, x, y, z) , z > y.
loop(6, x, y, z) :- loop(5, x, y, z), z <= y.

Res() :- loop(6, x, y ,z), x = y, y = z."

echo $PROG > ./pp1.dl


