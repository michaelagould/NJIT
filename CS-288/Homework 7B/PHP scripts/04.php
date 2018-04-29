<html>
<head>
	<title>switch Statement</title>
</head>
<body>
<?php
	$weather = 'rain';
	echo "The weather forecast calls for $weather. ";
	switch ($weather) {
		case 'snow':
			echo "You'd better bundle up!";
			break;
		case 'rain':
			echo "Be sure to bring an umbrella!";
			break;
		case 'wind':
			echo "Take the day off and fly a kite!";
			break;
		default:
			echo "So who knows what to expect?!";
			break;
	}
?>
</body>
</html>
