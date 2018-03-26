#!/bin/bash
array=($@)
for (( i = 1; i < ${#array[@]}; i++ )); 
do
	for (( j = $i-1; j >= 0 && ${array[$j]} < ${array[(($j-1))]} ; j-- )); do
		temp=${array[(($j-1))]}
		array[(($j-1))]=${array[$j]}
		aray[$j]=$temp
	done
done
echo ${array[@]}

#    int temp = $1;
#    a = b;
#    b = temp;
