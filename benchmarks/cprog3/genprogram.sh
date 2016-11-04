#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $1 in
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

PROG=".decl loop(i:number, x:number, y:number, z:number)
.decl R() output

loop(0, 0, ${LOW}, 0).
loop(1, ${HIGH}, y, z) :- loop(0, _, y, z).
loop(2, x, y, z) :- loop(1, x, _, _), loop(0, _, y, z), x - z > 0.
loop(3, x, y, z*-1) :- loop(1, x, y, z), x - z <= 0.
loop(4, x, y, z) :- loop(2, x, y, z).
loop(4, x, y, z) :- loop(3, x, y, z).
loop(5, x, y, z) :- loop(4, x, y, z).
loop(5, x-1, y, z) :- loop(5, x, y, z), x > 0. 
R() :- loop(5, _, _, z), z >= 0. x = 0"

echo $PROG > ./cprog3.dl


