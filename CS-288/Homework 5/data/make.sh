#!/bin/bash

for (( i = 0; i < $1; i++ )); 
do
	echo "$RANDOM" >> "$1.data"
done