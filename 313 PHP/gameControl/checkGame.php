<?php
$dbHost = getenv('OPENSHIFT_MYSQL_DB_HOST');

//checks where I am working, if its on home use first
//else I am on openshift.
if ($dbHost === null || $dbHost == "")
{
//	not in the openshift environment
	$dbHost = "localhost";
	$dbUser = "php";
	$dbPassword = "php-pass";
	$dbName = "user";
	
}
else
{
	//in the openshift environ...
	$dbPort = getenv('OPENSHIFT_MYSQL_DB_PORT');
	$dbUser = getenv('OPENSHIFT_MYSQL_DB_USERNAME');
	$dbPassword = getenv('OPENSHIFT_MYSQL_DB_PASSWORD');
	$dbName = "GameControl";
	$dbHost = $dbHost . ":" . $dbPort;
}

//trys to connect to the database, if not it stops everything
try {
	$db = new PDO("mysql:host=$dbHost; dbname=$dbName", $dbUser, $dbPassword);
}
catch (PDOException $ex)
{
	die();
}

$temp = $db->query("SELECT name FROM game");
$game = $temp->fetchAll(PDO::FETCH_ASSOC);

$name = $_POST['game'];
$lowName = strtolower($name);

$open = true;
foreach($game as $game1)
{
	foreach($game1 as $row)
	{
		$lowRow = strtolower($row);
		if ($lowName == $lowRow)
		{
			$open = false;
			break;
		}
	}
}

if($open)
	echo "true";
else
	echo "false";

?>