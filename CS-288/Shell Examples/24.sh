#!/bin/bash

names='Kyle Cartman Stan Quit'
PS3='Select character: '

select name in $names
do
	if [ $name == 'Quit' ]
	then
		break
	fi
	echo Hello $name
done

# 1) Kyle
# 2) Cartman
# 3) Stan
# 4) Quit
# Select character: 
