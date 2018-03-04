#!/bin/bash
directoryName='./test' ## destination folder
fileString=$(ls $directoryName) ## string of contents from destination folder path
fileList=($fileString)
index=0
exception=()

for file in ${fileList[@]}
do
	if [ -e $directoryName/$1$(printf %03d $index).$2 ]
	then
		exception=(${exception[@]} + ${fileList[index]})
		let index++
	else
		let index++
	fi
done

index=0

for file in ${fileList[@]}
do
	if [ $directoryName/$1$(printf %03d $index).$2 = ${exception[$index]} ]
	then
		let index++
	else 
		mv $directoryName/${fileList[$index]} $directoryName/$1$(printf %03d $index).$2
		let index++
	fi
done