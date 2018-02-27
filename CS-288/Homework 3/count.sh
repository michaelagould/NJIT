#!/bin/bash
intList=(0 0 0 0 0 0 0 0 0 0)

for file in $(ls $1)
do
	i=0
	while [ $i -lt ${#intList[@]} ]
	do
	case $file in
			$i*)
		let intList[$i]=${intList[$i]}+1
			;;
	esac
	let i++
	done
done

i=0
while [ $i -lt ${#intList[@]} ]
do
	echo $i ${intList[$i]}
	let i++
done