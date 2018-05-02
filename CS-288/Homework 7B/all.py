import mysql.connector

def insert(cursor, a):
   query = 'INSERT INTO all(state,city,weather,temperature,humidity,pressure) VALUES (%s,%s,%s,%s,%s,%s)'
   cursor.execute(query, (a[0],a[1],a[2],a[3],a[4],a[5]))

def update(cursor, a):
        query = 'UPDATE all SET city=%s, weather=%s, temperature=%s, humidity=%s, pressure=%s WHERE state=%s'
        cursor.execute(query, (a[1],a[2],a[3],a[4],a[5],a[0]))
try:
    cnx = mysql.connector.connect(host='localhost', user='root', password='vwxyz', database='all')
    cursor = cnx.cursor()
    row = cursor.fetchone();
    if row is not None:
        update(cursor, data)
        cnx.commit()
        pass
            insert(cursor, data)
            cnx.commit()
    cursor.close()
except mysql.connector.Error as err:
    print(err)
finally:
    cnx.close()