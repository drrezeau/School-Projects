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

$name = $_POST['name'];
$players = $_POST['players'];
$description = $_POST['description'];
$rating = $_POST['rating'];
$category = $_POST['category'];


$temp = $db->prepare('INSERT INTO  game (name, numOfPlayers, description, rating, categoryId) VALUES (:name, :players, :description, :rating, :category)');
$temp->bindParam(':name', $name);
$temp->bindParam(':players', $players);
$temp->bindParam(':description', $description);
$temp->bindParam(':rating', $rating);
$temp->bindParam(':category', $category);
$temp->execute();

if (isset($_COOKIE['user']))
	header("Location: userHomepage.php");
else
	header("Location: homepage.html");
?>