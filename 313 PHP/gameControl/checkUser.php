<?php
/********************************
* this is going to check the user
*name to make sure it is not taken.
* if it is, it returns false.
********************************/


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

$checkUser = strtolower($_POST['user']);

$temp = $db->query("SELECT userName FROM user");
$user = $temp->fetchAll(PDO::FETCH_ASSOC);

$open = true;
foreach($user as $user1)
{
	foreach($user1 as $row)
	{
		if ($checkUser == $row)
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