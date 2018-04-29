<html>
<head>
	<title>Functions</title>
</head>
<body>
<?php
	function paycheck($hourlyRate, $hoursWorked) {
		$wage = $hourlyRate * $hoursWorked;
		return $wage;
	}

	echo paycheck(12, 40);
?>
</body>
</html>
