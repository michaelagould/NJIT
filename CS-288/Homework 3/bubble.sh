#!/bin/bash

i=0
j=0
temp=0
count=0

while [ $(expr $count + 1) -le $# ];
do
	intList[$count]=$[$count]
	let count++
done

while [ $i -lt ${#intList[@]} ] 
do
	while [ $j -lt $(expr ${#intList[@]} - $i - 1) ] 
	do
		if [ ${intList[$j]} -gt ${intList[$(expr $j - 1)]} ]
		then
			temp=${intList[$j]}
			intList[$j]=${intList[$j+1]}
			intList[$j+1]=$temp
		fi
		let j++
	done
	let i++
done