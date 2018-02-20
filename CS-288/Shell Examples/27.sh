#!/bin/bash

print_something () {
	echo Hello $1
	return 0
}

print_something Mars
echo The last function returned $?
