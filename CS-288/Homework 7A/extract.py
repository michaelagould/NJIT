import sys, xml.dom.minidom
import csv

filename = "output.csv"

with open(filename, 'a') as f:
	
	document = xml.dom.minidom.parse(sys.argv[1])
	heading1_Elements = document.getElementsByTagName('h1')
	heading4_Elements = document.getElementsByTagName('h4')
	td_Elements = document.getElementsByTagName('td')

	state = sys.argv[2]
	city = sys.argv[3]
	i = 4
	for args in range(i, len(sys.argv)):
		city = city + " " + sys.argv[i]
		i= i + 1
	weather = heading4_Elements[2].childNodes[0].nodeValue.encode('ascii', 'ignore')
	temperature = heading1_Elements[1].childNodes[0].nodeValue.encode('ascii', 'ignore')
	humidity = td_Elements[1].childNodes[0].nodeValue.encode('ascii', 'ignore')
	pressure = td_Elements[5].childNodes[0].nodeValue.encode('ascii', 'ignore')

	#print(state)
	#print(city)
	#print(weather)
	#print(temperature)
	#print(humidity
	#print(pressure)

	f.write(",".join([state, city, weather, temperature[:2], humidity[:2], pressure[33:38].strip()]) + "\n")