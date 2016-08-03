<!DOCTYPE html>

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

//gets all the different information from the different tables
$temp = $db->query("SELECT * FROM user");
$user = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM game");
$game = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM category");
$category = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM ownership");
$ownership = $temp->fetchAll(PDO::FETCH_ASSOC);
?>


<html>
	<head>
	<title>Game Control System</title>
	<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
	<link rel="stylesheet" href="Layout.css" />
	</head>
	
	<body>
		<header>
			<h1>Game Control</h1>
			<a href="login.php">Log In Page</a>
		</header>
		<div class="container">
		<p>
		<h2>Users</h2>
		<table border="1" class="table table-hover">
		<tr>
			<th>ID</th>
			<th>UserName</th>
			<th>Password</th>
			<th>first Name</th>
			<th>Last Name</th>
			<th>Email</th>
		</tr>
	<?php
    //displays the users
   $size = count($user);
	for($count = 0; $count < $size; $count++) 
	{ 
		echo "<tr>\n";
		echo "<td>" . $user[$count]['id'] . "</td>\n";
		echo "<td>" . $user[$count]['userName'] . "</td>\n";
		echo "<td>" . $user[$count]['password'] . "</td>\n"; 
		echo "<td>" . $user[$count]['firstName'] . "</td>\n";
		echo "<td>" . $user[$count]['lastName'] . "</td>\n";
		echo "<td>" . $user[$count]['email'] . "</td>\n";
		echo "</tr>\n";
	}?>
		</table>
		<h2>Categories</h2>
			
	<table class="table table-hover">
	<tr>
		<th>Category</th>
		<th>ID</th>
	</tr>
	
	<?php
	$size = count($category);
	for($count = 0; $count < $size; $count++) 
	{ 
		echo "<tr>\n";
		echo "<td>" . $category[$count]['name'] . "</td>\n";
		echo "<td>" . $category[$count]['id'] . "</td>\n";
		echo "</tr>\n";
	}
	?>
	</table>
		
	<h2>Games</h2>
	<table class="table table-hover">
		<tr>
		<th>ID</th>
			<th>Name</th>
			<th>Number of Players</th>
			<th>Description</th>
			<th>Rating</th>
			<th>Category</th>
		</tr>
		<?php
		$size = count($game);
		for($count = 0; $count < $size; $count++) 
		{ 
			echo "<tr>\n";
			echo "<td>" . $game[$count]['id'] . "</td>\n";
			echo "<td>" . $game[$count]['name'] . "</td>\n";
			echo "<td>" . $game[$count]['numOfPlayers'] . "</td>\n"; 
			echo "<td>" . $game[$count]['description'] . "</td>\n";
			echo "<td>" . $game[$count]['rating'] . "</td>\n"; 
			echo "<td>" . $category[$game[$count]['categoryId']-1]['name'] . "</td>\n";
			echo "</tr>\n";
		}
		?>
		</table>
			<h2>Ownership</h2>
	<table class="table table-hover">
		<tr>
			<th>User</th>
			<th>Game</th>
		</tr>
		<?php
		$size = count($ownership);
		for($count = 0; $count < $size; $count++) 
		{ 
			echo "<tr>\n";
			echo "<td>" . $user[$ownership[$count]['userId']-1]['userName'] . "</td>\n";
			echo "<td>" . $game[$ownership[$count]['gameId']-1]['name'] . "</td>\n"; 
			echo "</tr>\n";
		}
		?>
			
		</table>
	</p>
		</div>
	</body>
</html>




<!--SELECT name, description, id FROM game WHERE NAME LIKE '%%'-->