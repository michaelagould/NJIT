import sys, xml.dom.minidom, mysql.connector

def insert(cursor, a):
   query = "INSERT INTO data (state,city,weather,temperature,humidity,pressure) VALUES (%s,%s,%s,%s,%s,%s)"
   cursor.execute(query, (a[0],a[1],a[2],a[3],a[4],a[5]))

def update(cursor, a):
        query = "UPDATE data SET city=%s, weather=%s, temperature=%s, humidity=%s, pressure=%s WHERE state=%s"
        cursor.execute(query, (a[1],a[2],a[3],a[4],a[5],a[0]))
	
document = xml.dom.minidom.parse(sys.argv[1])
heading1_Elements = document.getElementsByTagName('h1')
heading4_Elements = document.getElementsByTagName('h4')
td_Elements = document.getElementsByTagName('td')
state = sys.argv[2].encode('ascii')
city = sys.argv[3].encode('ascii')
i = 4
for args in range(i, len(sys.argv)):
	city = city + " " + sys.argv[i]
	i= i + 1
city = city.encode('ascii')
weather = heading4_Elements[2].childNodes[0].nodeValue.encode('ascii', 'ignore')
temperature = heading1_Elements[1].childNodes[0].nodeValue.encode('ascii', 'ignore')
humidity = td_Elements[1].childNodes[0].nodeValue.encode('ascii', 'ignore')
pressure = td_Elements[5].childNodes[0].nodeValue.encode('ascii', 'ignore')
data = [state, city, weather, temperature[:2], humidity[:2], pressure[33:38].strip()]

try:
    cnx = mysql.connector.connect(host='localhost', user='root', password='mysqlpassword', database='weather')
    cursor = cnx.cursor()
    cursor.execute("SELECT * FROM data WHERE state='" + state + "'")
    row = cursor.fetchone()
    if row is not None:
        update(cursor, data)
        cnx.commit()
    else:
        insert(cursor, data)
        cnx.commit()
    cursor.close()
except mysql.connector.Error as err:
    print(err)
finally:
    cnx.close()