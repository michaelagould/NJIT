#!/bin/bash

# South Park characters
nameList=(Stan Kyle Cartman)

echo ${#nameList[@]}    # 3
echo ${nameList[@]}     # Stan Kyle Cartman
echo ${!nameList[@]}    # 0 1 2
echo ${nameList[0]}     # Stan
echo ${#nameList[0]}    # 4
echo ${nameList[@]:1:2} # Kyle Cartman

n=0
while [ $n -lt ${#nameList[@]} ]
do
	echo ${nameList[$n]}
	(( n++ ))
done

for name in ${nameList[@]}
do
    echo $name
done
