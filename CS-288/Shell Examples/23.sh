#!/bin/bash

for n in 1 2 3 4 5 6 7 8 9
do
	if [ $n -eq 3 ]
	then
		continue
	elif [ $n -eq 7 ]
	then
		break
	fi

	echo $n
done
