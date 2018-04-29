<html>
<head>
	<title>Arrays</title>
</head>
<body>
<?php
	$footballTeam[] = "Jets";
	$footballTeam[] = "Lions";
	$footballTeam[] = "Dolphins";

	$footballTeam[0] = "Jets";
	$footballTeam[1] = "Lions";
	$footballTeam[2] = "Dolphins";

	$footballTeam = array("Jets", "Lions", "Dolphins");

	$size = count($footballTeam);
	for ($i = 0; $i < $size; $i++)
		echo '$footballTeam[' . $i . '] is ' . $footballTeam[$i] . '<br />';
?>
</body>
</html>
