#!/bin/bash
fileList=(ls *)
count=1

while [$count -le ${fileList[@]}]
if ["${fileList[$count]}" != "$1.$2$count"]
then
	do
		mv "${fileList[$count]}" "$1.$2$count"
		(( count++ ))
	fi
	(( count++ ))
done