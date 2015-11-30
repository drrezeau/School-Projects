<!--NEEDS TO BE MADE
    on user page->add the search feature
		*add a game page and php
		*better display for each game
		-->


<!DOCTYPE html>
<html>
	<head>
		<title>Game References Homepage</title>
		<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
		<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
		<link rel="stylesheet" href="Layout.css" />
	</head>
	
	<body>
		<header>
			<h1>Game Collections</h1>
			
						<?php
echo "<select style=\"color:black\" onchange=\"location = this.options[this.selectedIndex].value\">\n";
echo "<option value=\"homepage.php\">Menu</option>\n";
echo "<option value=\"homepage.php\">Search Games</option>\n";
if (isset($_COOKIE['user'])) //links to show if logged in
{
	echo "<option value=\"userHomepage.php\">My homepage</option>\n";
	echo "<option  value=\"newGame.html\">Add a New Game</option>\n";
	//echo "<option>Search Owned Games</option>\n";
	echo "<option value=\"logout.php\" >Logout</option>\n";
}
else //links to show if not logged in
{
	echo "<option value=\"login.php\">Log In</option>\n";
}
echo "</select>\n";
?>
		</header>
		
		<div><h1>Search for Games!</h1></div>
		<div>
			<form action="findGames.php" method="POST">
				<input type="text" name="search" style="font-size:175%; margin: 50px; width:80%" /> <br />
				<div class="col-md-4"></div>
				<div class="col-md-4">
				<button type="submit" class="btn btn-default btn-lg btn-block">search</button>
				</div>
			</form>
		</div>
	</body>
</html>