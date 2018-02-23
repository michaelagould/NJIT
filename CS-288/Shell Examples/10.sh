#!/bin/bash

a=$(( 4 + 5 ))
echo $a # 9

a=$((3*5-7))
echo $a # 8

b=$(( a + 3 ))
echo $b # 11

(( b++ ))
echo $b # 12
