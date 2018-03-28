#!/bin/bash
array=($@)
for (( i = 1; i < ${#array[@]}; i++ )); 
do
	key=${array[$i]}
<<<<<<< HEAD
	for (( j = $i-1; j >= 0 && array[$j] > key; j-- )); 
	do
		array[j+1]=${array[$j]}
	done
	array[$j+1]=$key
done
echo ${array[@]}
=======
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
>>>>>>> 07afc652e8ee06266a0ed693791a761bd43a61b7
