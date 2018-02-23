#!/bin/bash

print_something () {
	echo Hello $1 # function $1 scope != script $1 scope
}

print_something Mars # Mars is an argument to the function
