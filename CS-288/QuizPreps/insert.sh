#!/bin/bash
array=($@)
for (( i = 1; i < ${#array[@]}; i++ )); 
do
	key=${array[$i]}
	let "j = $i - 1" #this is weird
	while [[ j -gt 0 && array[$j] > key ]]; 
	do
		array[$(j+1)]=${array[$j]}
		j=$j-1
	done
	array[(($j+1))]=$key
done

echo ${array[@]}