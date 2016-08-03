<?php

require 'password.php';

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

$db = new PDO("mysql:host=$dbHost;dbname=$dbName", $dbUser, $dbPassword);

$user = strtolower($_POST['user']);
$password = $_POST['pswd'];
$first = $_POST['first'];
$last = $_POST['last'];
$email = $_POST['email'];

$passwordHash = password_hash($password, PASSWORD_DEFAULT);

$temp = $db->prepare('INSERT INTO  user (userName, password, firstName, lastName, email) VALUES (:user, :password, :first, :last, :email)');
$temp->bindParam(':user', $user);
$temp->bindParam(':password', $passwordHash);
$temp->bindParam(':first', $first);
$temp->bindParam(':last', $last);
$temp->bindParam(':email', $email);
$temp->execute();



header("Location: login.php");
?>




