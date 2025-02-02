#!/bin/bash

idx=0
philos=$1

while [ $((idx++)) -lt "$philos" ]
do		cat outfile | grep " $idx is eating" | wc -l
done
