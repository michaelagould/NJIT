#!/bin/bash
intList=("$@")
for(( i = 0; i < $($#-1); i++ )); 
do
	for(( j = 1; j < $($#-$i); j++ ));
	do
		if [ ${intList[$j]} -gt ${intList[$($j-1)]} ]
		then
			temp=${intList[$j]}
			intList[$j]=${intList[$(expr $j - 1 )]}
			intList[$($j-1)]=$temp
		fi
	done
	j=1
done

echo ${intList[@]}