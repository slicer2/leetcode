#!/bin/bash

RANDOM=1

for i in $(seq 1 20)
do
	line=""

	for x in $(seq 1 20)
	do
		let "y = $RANDOM % 100"
		line="$line $y"
	done

	#echo $line
	echo $line | ./main
done
