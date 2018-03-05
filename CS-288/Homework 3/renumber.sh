#!/bin/bash
directoryName='./test' ## destination folder
fileString=$(ls $directoryName) ## string of contents from destination folder path
fileList=($fileString) 
fileIndex=0

for file in ${fileList[@]}
do
	if [ -e $directoryName/$1$(printf %03d $fileIndex).$2 ]
	then
		exceptions=(${exceptions[@]} + $fileIndex)
	fi
	let fileIndex++
done

fileIndex=0
sem=0

for file in ${fileList[@]}
do
	for exception in ${exceptions[@]}
	do
		if [ $fileIndex = $exception ]
		then
			sem=1
			break
		if [ $fileIndex != $exception ]
		then
			if [ $exceptionIndex -eq ${#exception[@]} ]
			then
				mv $directoryName/$file $directoryName/$1$(printf %03d $fileIndex).$2
			fi
		fi
		fi
	done
	if [ $sem != 1 ]
	then
		mv $directoryName/$file $directoryName/$1$(printf %03d $fileIndex).$2
	fi
	let fileIndex++
done
