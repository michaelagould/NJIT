#!/bin/bash

a='Hello World'
echo ${#a} # prints 11 (len of a) -- {} are required since $# is a variable

b=4953
echo ${#b} # prints 4 -- 4952 == '4953' == "4953" 
