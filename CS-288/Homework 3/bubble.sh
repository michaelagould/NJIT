#!/bin/bash

i=0
j=1
temp=0
intList=("$@")

while [ $i -lt $(expr $# - 1) ] 
do
	limit=$(expr $# - $i)
	while [ $j -lt $limit ] 
	do
		if [ ${intList[$j]} -gt ${intList[$(expr $j - 1 )]} ]
		then
			temp=${intList[$j]}
			intList[$j]=${intList[$(expr $j - 1 )]}
			intList[$(expr $j - 1 )]=$temp
		fi
		let j++
	done
	let i++
	let j=1
done

echo ${intList[@]}