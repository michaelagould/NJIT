#!/bin/bash

read -p "Enter the name of an animal: " animal

case $animal in
	[Hh]orse | [Dd]og | cat)
		n=four
		;;
	[Hh]uman | [Kk]angaroo)
		n=two
		;;
	*)
		n="an unknown number of"
		;;
esac

echo The $animal has $n legs.
