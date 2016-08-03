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

$temp = $db->query("SELECT userName, firstName FROM user");
$user = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM category");
$category = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM ownership");
$ownership = $temp->fetchAll(PDO::FETCH_ASSOC);


/*
foreach($user as $user1)
{
	foreach($user1 as $row)
	{
		if($row == $_COOKIE['user'])
			$firstName = $user1['firstName'];
	}
}
*/


$button = $_POST['button'];
$value = $_POST['search'];

echo "Button: $button, Value: $value";

for($count = 0; $count < $size; $count++) 
{ 
	if ($ownership[$count]['userId'] == $_COOKIE['userId'])
	{
		$ownedGames[$logged] = $ownership[$count]['gameId'];
		$logged++;
	}
}

if($button == "keyword")
{
	echo "KEY";
	$temp = $db->prepare("SELECT * FROM game WHERE name LIKE :value");
	$temp->bindValue(':value', "%". $value . "%", PDO::PARAM_STR);
	$temp->execute();
	$game = $temp->fetchAll(PDO::FETCH_ASSOC);
}

if($button == "players")
{
	echo "PLAY";
	$temp = $db->prepare("SELECT * FROM game WHERE numOfPlayers LIKE :value");
	$temp->bindValue(':value', '%'.$value.'%');
	$temp->execute();
	$game = $temp->fetchAll(PDO::FETCH_ASSOC);
}

if($button == "category")
{
	echo "CAT";
	$size = count($category);
	for ($i = 0; $i < $size; $i++)
	{
		if($category[$i]['name'] == $value)
			$value = $category[$i]['id'];
	}
	$temp = $db->prepare("SELECT * FROM game WHERE categoryId LIKE :value");
	$temp->bindValue(':value', '%'.$value.'%');
	$temp->execute();
	$game = $temp->fetchAll(PDO::FETCH_ASSOC);
}


?>


<html>
	<head>
		<title>Game Search</title>
		<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
		<link rel="stylesheet" href="Layout.css" />
		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>

		
	</head>
	<body>
		<header fixed>
			<h1>Search Results</h1>
			
		<?php
echo "<select style=\"color:black\" onchange=\"location = this.options[this.selectedIndex].value\">\n";
echo "<option value=\"homepage.php\">Menu</option>\n";
echo "<option value=\"homepage.php\">Search Games</option>\n";
if ($_COOKIE['user'] == 'admin')
	echo "<option value=\"GameControl.php\">Game Control</option>";
if (isset($_COOKIE['user'])) //links to show if logged in
{
	echo "<option value=\"userHomepage.php\">My homepage</option>\n";
	echo "<option  value=\"newGame.html\">Add a New Game</option>\n";
//	echo "<option value=\"searchOwned.php\">Search Owned Games</option>\n";
	echo "<option value=\"logout.php\" >Logout</option>\n";
}
else //links to show if not logged in
{
	echo "<option value=\"login.php\">Log In</option>\n";
}
echo "</select>\n";
?>
		</header>





<h2>Games</h2>
	<table class="table">
		<tr>
			<th>Name</th>
			<th>Number of Players</th>
			<th>Description</th>
			<th>Rating</th>
			<th>Category</th>
		</tr>
		<?php
		$size = count($ownedGames);
		$size2 = count($game);
		for($count = 0; $count < $size; $count++) 
		{ 	
			for($x =0; $x < $size2; $x++)
          {
              if($game[$x]['id'] == $ownedGames[$count])
              {
                  echo "<tr>\n";
                  echo "<td>" . $game[$x]['name'] . "</td>\n";
                  echo "<td>" . $game[$x]['numOfPlayers'] . "</td>\n"; 
                  echo "<td>" . $game[$x]['description'] . "</td>\n";
                  echo "<td>" . $game[$x]['rating'] . "</td>\n"; 
                  echo "<td>" . $category[$game[$x]['categoryId']-1]['name'] . "</td>\n";
                  echo "</tr>\n";
              }
          }
		}
		?>
		</table>