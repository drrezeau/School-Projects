<html>
<head>
	<title>Search Owned Games</title>
	<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
	<link rel="stylesheet" href="Layout.css" />
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
</head>
<body>
<header>
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
//	echo "<option>Search Owned Games</option>\n";
	echo "<option value=\"logout.php\" >Logout</option>\n";
}
else //links to show if not logged in
{
	echo "<option value=\"login.php\">Log In</option>\n";
}
echo "</select>\n";
?>
	</header>
		
		<div><h1>Search Owned Games!</h1></div>
		<div>
			<form action="displayOwned.php" method="POST">
				<input type="text" name="search" style="font-size:175%; margin: 50px; width:80%" /> <br />
				<div class="col-md-4"><input type="submit" name="button" value="keyword" class="btn btn-default btn-lg btn-block">Search by Keyword</input>
</div>
				<div class="col-md-4">
				<input type="submit" value="players" name="button" class="btn btn-default btn-lg btn-block">Search by Number of Players</input>
				</div>
				<div class="col-md-4">
				<input type="submit" value="category" name="button" class="btn btn-default btn-lg btn-block">Search by Category</input>
				</div>
			</form>
		</div>
	</body>
</html>
</body>
</html>
