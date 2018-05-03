<html>
<head>
    <title>Weather</title>
</head>
<body>
<table align="center" border="1">
<?php
    $cnx = new mysqli('localhost', 'root', 'mysqlpassword', 'weather');

    if ($cnx->connect_error)
        die('Connection failed: ' . $cnx->connect_error);

    $query = 'SELECT * FROM all';
    $cursor = $cnx->query($query);
    while ($row = $cursor->fetch_assoc()) {
        echo '<tr>';
        echo '<td>' . $row['state'] . '</td><td>' . $row['city'] . '</td><td>' . $row['weather'] . '</td><td>' . $row['temperature'] . '</td><td>' . $row['humidity'] . '</td><td>' . $row['pressure'] '</td>';
        echo '</tr>';
    }

    $cnx->close();
?>
</table>
</body>
</html>