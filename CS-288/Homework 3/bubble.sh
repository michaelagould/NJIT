#!/bin/bash

i=0
j=0
temp=0
count=0

while[ (($count + 1)) -le $# ]
do
	intList[$count]=$[$count]
	((count++))
done

while [ i -lt ${#intList[@]} ] 
do
	while [ j -lt ((${#intList[@]} - $i - 1)) ] 
	do
		if [ intList[$j] -gt intList[(($j - 1))] ]
		then
			temp = ${intList[j]}
			intList[j] = ${intList[j+1]}
			intList[j+1] = $temp
		fi
		((j++))
	done
	((i++))
done