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

$temp = $db->query("SELECT userName, firstName FROM user");
$user = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM game");
$game = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM category");
$category = $temp->fetchAll(PDO::FETCH_ASSOC);

$temp = $db->query("SELECT * FROM ownership");
$ownership = $temp->fetchAll(PDO::FETCH_ASSOC);


foreach($user as $user1)
{
	foreach($user1 as $row)
	{
		if($row == $_COOKIE['user'])
			$firstName = $user1['firstName'];
	}
}
?>



<html>
    <head>
        <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
		  <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
		<link rel="stylesheet" href="Layout.css" />
    </head>
    <body>
        <header fixed>
            <h1>Welcome <?php echo $firstName ?></h1>
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
     		<h2>Owned Games</h4>
    	<?php
    
   	  $loggedId = count($userId);
		  $size = count($ownership);
        $logged = 0;
		  for($count = 0; $count < $size; $count++) 
		  { 
				if ($ownership[$count]['userId'] == $_COOKIE['userId'])
				{
					 $ownedGames[$logged] = $ownership[$count]['gameId'];
                $logged++;
				}
		  }
		  ?>
		  
		  <table class="table">
		  <tr>
		  
		  	<th>Name</th>
		  	<th>Players</th>
		  	<th>Description</th>
		  	<th>Rating</th>
		  	<th>Category</th>
		  </tr>
		  <?php
        $size = count($game);
        $size2 = count($ownedGames);
		for($count = 0; $count < $size2; $count++) 
		{ 
          for($x =0; $x < $size; $x++)
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
     		</div>
        
        
    </body>
</html>