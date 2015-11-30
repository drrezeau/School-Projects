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

//trys to connect to the database, if not it stops everything
try {
	$db = new PDO("mysql:host=$dbHost; dbname=$dbName", $dbUser, $dbPassword);
}
catch (PDOException $ex)
{
	die();
}

$temp = $db->query("SELECT userName, password, id FROM user");
$user = $temp->fetchAll(PDO::FETCH_ASSOC);

$login = strtolower($_POST['login']);
$password = $_POST['password'];
$userfound = false;
$pswdPass = false;

 $size = count($user);
for($count = 0; $count < $size; $count++) 
{ 		
    if ($login == $user[$count]['userName'])
	 {
		 $userfound = true;
        if(password_verify($password, $user[$count]['password'])) 
        {
			  $id = $user[$count]['id'];
//            echo "LOGGED IN";
            setcookie('user', $login, time() + 2*3600); //86400 minutes in one day. 3600 is an hour
			  setcookie('userId', $id, time() + 2*3600); //stay for two hours
//			  header("Location: userHomepage.php");
			  echo "true";
//			  return;
        }
		 else
		 {
			 echo "Password incorrect";
			 return;
		 }
    }
}

if (!$userfound)
	echo "Username not Found";

//echo "false";
//header("Location: login.php");
?>