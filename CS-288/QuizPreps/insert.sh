#!/bin/bash
array=($@)
for (( i = 1; i < ${#array[@]}; i++ )); 
do
	key=${array[$i]}
	echo "test: $key"
	((j=$i-1))
	echo "index: $j"
	while [[ j -ge 0 ]]; 
	do
		if [ ${array[$j]} -gt $key ]
		then
			echo "index: $j"
			array[((j+1))]=${array[$j]}
			echo ${array[@]}
			read this
		fi
		((j=$j-1))
		echo "next while index: $j"
		read this
	done
	array[(($j+1))]=$key
	echo ${array[@]}
	read this
done