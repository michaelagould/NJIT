#!/bin/bash

StateList=(NY 'New York City' 40.78 -73.97 
CA 'Los Angeles' 34.02 -118.45 
IL Chicago 41.78 -87.76 
TX Houston 29.64 -95.28 
AZ Phoenix 33.69 -112.07 
PA Philadelphia 40.08 -75.01 
FL Jacksonville 30.23 -81.67 )

for((i = 0; i < ${#StateList[@]}; i = i + 4)){
	state=${StateList[$i]};
	city=${StateList[$i+1]}
	lat=${StateList[$i+2]}
	long=${StateList[$i+3]}
	output=$(date +"%F-%I-%M-%S")-$state
	wget -O $output.html https://forecast-v3.weather.gov/point/$lat,$long?view=plain
	java -jar tagsoup-1.2.1.jar --files $output.html
	python extract.py $output $state $city
	rm $output.html #$output.xhtml 
}