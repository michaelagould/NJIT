#!/bin/bash

# $0 - The name of the script.
# $1 - $9 - The first 9 arguments to the script.
# $# - Number of arguments that were passed to the script.
# $@ - All the arguments supplied to the script.
# $? - The exit status of the most recently run process.

echo '$#:' $#
echo '$0:' $0
echo '$1:' $1
echo '$@:' $@
