#!/bin/bash
array=($@)
for (( i = 1; i < ${#array[@]}; i++ )); 
do
	echo $i
	echo ${array[@]}
	read this
	for (( j = $i-1; j >= 0 && ${array[$j]} < ${array[(($j-1))]} ; j-- ))
	do
		temp=${array[(($j-1))]}
		array[(($j-1))]=${array[$j]}
		aray[$j]=$temp
		echo $j
		echo ${array[@]}
		read this
	done
done
echo ${array[@]}