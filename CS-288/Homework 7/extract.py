import sys, xml.dom.minidom
import csv

with open('output.csv', 'a') as f:
	writer = csv.writer(f)
	
	document = xml.dom.minidom.parse(sys.argv[1])
	heading1_Elements = document.getElementsByTagName('h1')
	heading4_Elements = document.getElementsByTagName('h4')
	bold_Elements = document.getElementsByTagName('b')

	state = sys.argv[2]
	city = sys.argv[3]
	weather = heading4_Elements[2].childNodes[0].nodeValue
	temperature = heading1_Elements[1].childNodes[0].nodeValue
	humidity = bold_Elements[3].childNodes[0].nodeValue
	pressure = bold_Elements[5].childNodes[0].nodeValue
	
	writer.writerow([state, city, weather, temperature, humidity, pressure])