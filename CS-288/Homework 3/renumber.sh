#!/bin/bash
directoryName='./test' ## destination folder
fileString=$(ls $directoryName) ## string of contents from destination folder path
fileList=($fileString)
index=0

for file in ${fileList[@]}
do
done


for file in ${fileList[@]}
do
	if [ -e $directoryName/$1$(printf %03d $index).$2 ]
	then
		let index++
	else 
		mv $directoryName/${fileList[$index]} $directoryName/$1$(printf %03d $index).$2
		let index++
	fi
done