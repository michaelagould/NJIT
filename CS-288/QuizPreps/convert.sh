#!/bin/bash

InToFt () {
	((answer = $1/12))
	echo $answer
	echo "ft"
}

InToYd () {
	(( answer = $1/36 ))
	echo $answer
	echo "yd(s)"
}

FtToIn () {
	answer=$1*12
	echo $answer
	echo "in(s)"
}

FtToYd () {
	answer=$1/3
	echo $answer
	echo "yd(s)"
}

YdToIn () {
	answer=$($1*36)
	echo $answer
	echo "in(s)"
}

YdToFt () {
	answer=$($1*3)
	echo $answer
	echo "ft"
}

echo "Enter a number:"
read number

if [ "$number" -eq "$number" ]
then
	echo "Enter a unit type(in, ft, or yd):"
	read type
	case "$type" in  
		"in") echo "That would be: " InToFt $number " " InToYd $number
		;;
		"ft") echo "That would be: " FtToIn $number " " FtToYd $number
		;;
		"yd") echo "That would be: " $(YdToIn $number) " " YdToFt $number
		;;
		*) echo "What terrible input, you should be ashamed of yourself"
		;;
	esac

else
	echo "Invalid number, quitting"
fi

