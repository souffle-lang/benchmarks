#!/bin/bash
. `dirname $BASH_SOURCE[0]`/../utils.sh

case $1 in
    small)
        LOW1=-10          # number of entries
        HIGH1=10           # range of entries
        LOW2=0          # number of entries
        HIGH2=10           # range of entries
        ;;
    medium)
        LOW1=-100          # number of entries
        HIGH1=100           # range of entries
        LOW2=0          # number of entries
        HIGH2=100           # range of entries        ;;
    large)
        LOW1=-1000          # number of entries
        HIGH1=1000           # range of entries
        LOW2=0          # number of entries
        HIGH2=1000           # range of entries        ;;
        ;;
    xlarge)
        LOW1=-10000          # number of entries
        HIGH1=10000           # range of entries
        LOW2=0          # number of entries
        HIGH2=10000           # range of entries        ;;
        ;;
esac

PROG=".decl tak(X:number, Y:number, Z:number, V:number, Q:number)

tak(X,Y,Z,Y,0) :- Y >= X, natural(X), natural(Y), natural(Z).
tak(X,Y,Z,V,Q1+Q2+Q3+Q4+1) :- tak(X-1,Y,Z,V1,Q1), tak(Y-1,Z,X,V2,Q2), tak(Z-1,X,Y,V3,Q3), 
                              tak(V1,V2,V3,V,Q4), Y < X.

.decl natural(N:number)

natural(${LOW1}).

natural(n+1) :- natural(n), n < {$HIGH1}.
.decl query(N: number, Q:number) output

query(N, Q) :- tak(N, 0, N+1, _, Q), N >= ${LOW2}, N < ${HIGH2}."

echo $PROG > ./cprog1.dl


