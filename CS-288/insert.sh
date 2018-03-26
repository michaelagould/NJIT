#!/bin/bash

array=(1 3 7 5 2 4)

for i in ${!array[@]} 
do
	temp=${array[i]}
	j=${#array[i]}
	while[ j > 0 ] 
	do
		if[ j-1 < 0 && temp < $array[j-1] ]

		fi
		((j--))
	done
done

for ((i=0; i < length(array))