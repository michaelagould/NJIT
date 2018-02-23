#!/bin/bash

# Supported operators: +, -, ++, --, *,  /,  %, ** (exponentiation)

let a=5+4 # no spaces allowed unless the expression is quoted
echo $a # prints 9

let "a = 5 + 4"
echo $a # prints 9

let a++
echo $a # prints 10

let "a = a * 4"
echo $a # prints 40
