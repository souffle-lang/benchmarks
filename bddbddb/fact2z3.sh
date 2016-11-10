#!/usr/bin/bash
filename=$1".facts"
while read -r line
do
    name=$line
    name2=$(echo "$name" | sed "s/ /,/g")
    echo $1"("$name2")." >> $1.dl
done < "$filename"


