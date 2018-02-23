#!/bin/bash

expr 5 + 4 # prints 9 -- spaces are required

expr "5 + 4" # string "5 + 4" because spaces inside quotes don't count

expr 5+4 # string "5+4" because no spaces were used

expr 5 \* $1 # prints 5*"1st arg" -- backslash is required with *

expr 11 % 2 # prints 1

a=$( expr 10 - 3 ) # $( ... ) needed to capture output
echo $a # prints 7
