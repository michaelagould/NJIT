<html>
<head>
	<title>if/else Statement</title>
</head>
<body>
<?php
	$weather = 'rain';
	echo "The weather forecast calls for $weather. ";
	if ($weather == 'snow')
		echo "You'd better bundle up!";
	else if ($weather == 'rain')
		echo "Be sure to bring an umbrella!";
	else if ($weather == 'wind')
		echo "Take the day off and fly a kite!";
	else
		echo "So who knows what to expect?!";
</body>
</html>
