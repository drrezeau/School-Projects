<?php

$dbHost = "";
$dbPort = "";
$dbUser = "";
$dbPassword = "";

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

$temp = $db->query("SELECT * FROM category");
$category = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM ownership");
$ownership = $temp->fetchAll(PDO::FETCH_ASSOC);

$value =$_POST["search"];

$temp = $db->prepare("SELECT * FROM game WHERE name LIKE :value");
$temp->bindValue(':value', "%". $value . "%", PDO::PARAM_STR);
$temp->execute();
$game = $temp->fetchAll(PDO::FETCH_ASSOC);
?>




<!DOCTYPE html>
<html>
	<head>
		<title>Game Search</title>
		<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
		<link rel="stylesheet" href="Layout.css" />
	   <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>

		<script>
		$(document).ready(function(){
    $("button").click(function(){
		 $.post("addOwnedGame.php",
				  {
			 		gameId : $(this).attr('value')
		 		  },	
				  function(data, status) {
		 });
    });
});
			
			$(document).ready(function(){
				$("button").click(function() {
					$(this).replaceWith("Game Added")
				});
			});
		</script>
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
		<div class="container"> 
		
		<h2>Games</h2>
	<table class="table">
		<tr>
		<?php
			if (isset($_COOKIE['user']))
				 {
					 echo "<th colspan=\"2\">Name</th>";
				 }
			else
				 {
					 echo "<th>Name</th>";
				 }
				 ?>
			
			
			<th>Number of Players</th>
			<th>Description</th>
			<th>Rating</th>
			<th>Category</th>
		</tr>
		<?php
		$size = count($game);
		for($count = 0; $count < $size; $count++) 
		{ 
			$x = $game[$count]['id'];
			$owned = false;
			$size2 = count($ownership);
			for ($w = 0; $w < $size2; $w++)
			{
				if ($ownership[$w]['gameId'] == $x)
				{
					if ($ownership[$w]['userId'] == $_COOKIE['userId'])
					{
						$owned = true;
						break;
					}
				}
			}
				
			echo "<tr>\n";
			if (isset($_COOKIE['user']) && !$owned)
			{
				echo "<td><button type=\"button\" id=\"game".$game[$count]['id']."\" value=\""
					.$game[$count]['id']."\">Add Game</button></td>\n";
			}
			else if (isset($_COOKIE['user']))
				echo "<td>Game Owned</td>";
			echo "<td>" . $game[$count]['name'] . "</td>\n";
			echo "<td>" . $game[$count]['numOfPlayers'] . "</td>\n"; 
			echo "<td>" . $game[$count]['description'] . "</td>\n";
			echo "<td>" . $game[$count]['rating'] . "</td>\n"; 
			echo "<td>" . $category[$game[$count]['categoryId']-1]['name'] . "</td>\n";
			echo "</tr>\n";
		}
		?>
		</table>
		</div>
	</body>
</html>