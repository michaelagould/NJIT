<html>
<head>
	<title>while Loop</title>
</head>
<body>
<?php
	$num = 5;
	$factorial = 1;
	while ($num > 1)
	    $factorial *= $num--;
	echo "Factorial: $factorial";
?>
</body>
</html>
