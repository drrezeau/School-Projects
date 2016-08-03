<?php 
if (isset($_COOKIE['user']))
    header("Location:userHomepage.php");
?>

<!DOCTYPE html>

<html>
	<head>
		<link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
		<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
		<link rel="stylesheet" href="Layout.css" />
		
		
		<script>
		$(document).ready(function(){
				$("#submit").click(function() {
					$.post("checkLogIn.php",
							 {
								login: $("#username").val(),
								password: $("#password").val()
							 },
							 function(data) {
						if (data == "true")
							window.location.href = "http://php-drrezeau.rhcloud.com/gameControl/userHomepage.php";
						else
							alert(data);
					});
				});
			});
		</script>
	</head>
	<body>
		<header>
			<h1>Welcome to Game Collections</h1>
<!--			<a href="homepage.html">Search</a>-->
			
						<?php
echo "<select style=\"color:black\" onchange=\"location = this.options[this.selectedIndex].value\">\n";
echo "<option value=\"homepage.php\">Menu</option>\n";
echo "<option value=\"homepage.php\">Search Games</option>\n";
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
		<h4>Please log in</h4>
		
		<form>
			<label><span>Username:</span> <input type="text" id="username" name="login" style="text-align:center" /></label><br> 
			<label><span style="margin-left:9px">Password:</span> <input type="password" id="password" name="password" style="text-align:center" /></label> <br>
			<div style="margin-left:93px"><button type="submit" id="submit" class="btn btn-default">Log In</button></div>
		</form>
		<div style="margin-left:72px"><a href="createUser.php" style="color:black" name="create">Create new User</a></div>
	</body>
</html>