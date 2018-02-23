#!/bin/bash
intList=(0 0 0 0 0 0 0 0 0 0)

for file in $(ls $1)
do
	i=0
	while [ $i -lt ${#intList[@]} ]
	do
	case $file in
			$i*)
		intList[$i]=$i ##fix to tally
			;;
	esac
	let i++
	done
done

echo ${intList[@]}