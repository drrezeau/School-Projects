<?php
session_start();
if ($_SESSION["sent"])
{
	header('Location: survey.php');
}

?>
<!DOCTYPE hmtl>

<html>
	
	<head>
	<title> David's Survey</title>
	<link rel="stylesheet" href="../homepage/Layout.css" />
	</head>
	<body>
		<header>
		<h1>Lord of the Rings Survey</h1>
		</header>
	
		<div>
			<form action="survey.php" method="post">
				<p class="center">What is your favorite Character?</p>
				<input type="radio" name="character" value="Aragorn" required/>Aragorn 
				<input type="radio" name="character" value="Gandalf" />Gandalf
				<input type="radio" name="character" value="Frodo" />Frodo<br />
				<input type="radio" name="character" value="Gollum" />Gollum
				<input type="radio" name="character" value="Sauron" />Sauron
				<input type="radio" name="character" value="Sam" />Sam<br />
				<input type="radio" name="character" value="Saruman" />Saruman
				<input type="radio" name="character" value="Legolas" />Legolas
				<input type="radio" name="character" value="Gimli" />Gimli<br /><br />
				<p class="center">Which battle scene do you love the most?</p>
				<input type="radio" name="battle" value="Weather Top" required/>Weather top
				<input type="radio" name="battle" value="Helm's Deep" />Helm's Deep
				<input type="radio" name="battle" value="Minas Tirith" /> Minas Tirith
				<input type="radio" name="battle" value="The Black Gate" /> The Black Gate <br /> <br />
				<p class="center"> Which Female character is your favorite?</p> 
				<input type="radio" name="female" value="Arwen" required/>Arwen
				<input type="radio" name="female" value="Eowyn" />Eowyn
				<input type="radio" name="female" value="Galadriel" /> Galadriel <br /> <br />
				<p class="center">Which of the three movies is the best?</p> 
				<input type="radio" name="movie" value="The Fellowship of the Ring" required/> The Fellowship of the Ring
				<input type="radio" name="movie" value="The Two Towers" /> The Two Towers
				<input type="radio" name="movie" value="The Return of the King" /> The Return of the King
				<br /> <br />
				<input type="submit" name="submit" value="Submit" />
				<input type="reset" name="reset" value="Reset" />
			</form>
		</div>	
	</body>
	
	<footer><a href="../homepage/homepage.html" style="color:white">Homepage</a></footer>
</html>