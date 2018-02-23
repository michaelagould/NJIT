#!/bin/bash
filestring=$(ls ~/git/NJIT/CS-288/'Homework 3'/test) ## list from destination folder path
fileList=($filestring)
index=0

for file in ${fileList[@]}
do
	if [ -e .test/$1.$2$index ]
	then
		echo this
		(( index++ ))
	else 
		mv ./test/${fileList[$index]} ./test/$1.$2$index ## sets to destination folder
		(( index++ ))
	fi
done