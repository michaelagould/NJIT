!#/bin/bash
A=($@)

for((i = 1; i < ${#A[@]}; i++)); 
do
	key=${A[i]}
	for((j = i; j > 0; j-- ));
	do
		if [ array[$($j-1)] > array[$j]]
		then
			A[j-1]=${A[$j]}
		fi
	done
done