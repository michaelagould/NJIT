#!/bin/bash
array=($@)
for (( i = 1; i < ${#array[@]}; i++ )); 
do
	key=${array[$i]}
	for (( j = $i-1; j >= 0 && array[$j] > key; j-- )); 
	do
		array[j+1]=${array[$j]}
	done
	array[$j+1]=$key
done
echo ${array[@]}