#!/bin/bash
array=($@)
for((i = 0; i < ${#array[@]}; i++));
do
	mindex=$i
	for((j = $i + 1; j < ${#array[@]}; j++));
	do
		if [[ ${array[$j]} -lt ${array[$mindex]} ]]
		then
			mindex=$j
		fi
	done
	temp=${array[mindex]}
	array[$mindex]=${array[$i]}
	array[$i]=$temp
done
echo ${array[@]}