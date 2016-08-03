<?php
session_start();

$temp = unserialize( file_get_contents("survey.txt"));
?>




<!DOCTYPE html>
<html>
	<head>
		<title>Survey Results</title>
		<link href="css/bootstrap.css" rel="stylesheet">
	 	<link rel="stylesheet" href="../homepage/Layout.css" />
	</head>
	<body>
		<header>
			<h1> Survey Results</h1>
		</header>


<div class="container">
		<h3>Favorite Characters</h3>
		<div class="container-fluid">
		
			<h4>Aragorn</h4>	
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Aragorn"]?>%'>
				<?php echo $temp["Aragorn"]?></div>
			</div>
			
			<h4>Gandalf</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Gandalf"]?>%'>
				<?php echo $temp["Gandalf"]?></div>
			</div>
			
			<h4>Frodo</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Frodo"]?>%'>
				<?php echo $temp["Frodo"]?></div>
			</div>
			
			<h4>Gollum</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Gollum"]?>%'>
				<?php echo $temp["Gollum"]?></div>
			</div>
			
			<h4>Sauron</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Sauron"]?>%'>
				<?php echo $temp["Sauron"]?></div>
			</div>
			
			<h4>Sam</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Sam"]?>%'>
				<?php echo $temp["Sam"]?></div>
			</div>
			
			<h4>Saruman</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Saruman"]?>%'>
				<?php echo $temp["Saruman"]?></div>
			</div>
			
			<h4>Legolas</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Legolas"]?>%'>
				<?php echo $temp["Legolas"]?></div>
			</div>
			
			<h4>Gimli</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Gimli"]?>%'>
				<?php echo $temp["Gimli"]?></div>
			</div>
			
		</div>
		
		<h3>Favorite Battle Scenes</h3>
		<div class="container-fluid">
		<h4>
			<span style="color:darkred">Weather Top</span>
			<span  style="color:darkblue; margin-left:5px">Helm's Deep</span>
			<span style="color:darkgreen; margin-left:5px">Minas Tirith</span>
			<span style="color:indigo; margin-left:5px">The Black Gate</span>
		</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkred' style='width:<?php echo $temp["Weather Top"]?>%'>
				<?php echo $temp["Weather Top"]?></div>
				
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Helm's Deep"]?>%'>
				<?php echo $temp["Helm's Deep"]?></div>
				
				<div class='progress-bar progress-bar-darkgreen' style='width:<?php echo $temp["Minas Tirith"]?>%'>
				<?php echo $temp["Minas Tirith"]?></div>
				
				<div class='progress-bar progress-bar-indigo' style='width:<?php echo $temp["The Black Gate"]?>%'>
				<?php echo $temp["The Black Gate"]?></div>
			</div>
		</div>
			
		<h3>Favorite Female Characters</h3>
		<div class="container-fluid">
		<h4>
			<span style="color:darkred">Arwen</span>
			<span  style="color:darkblue; margin-left:5px">Eowyn</span>
			<span style="color:darkgreen; margin-left:5px">Galadriel</span>
		</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkred' style='width:<?php echo $temp["Arwen"]?>%'>
				<?php echo $temp["Arwen"]?></div>
				
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["Eowyn"]?>%'>
				<?php echo $temp["Eowyn"]?></div>
				
				<div class='progress-bar progress-bar-darkgreen' style='width:<?php echo $temp["Galadriel"]?>%'>
				<?php echo $temp["Galadriel"]?></div>
			</div>
			</div>
			
			
		<h3>Favorite Movie</h3>
		<div class="container-fluid">
		<h4>
			<span style="color:darkred">The Fellowship of the Ring</span>
			<span  style="color:darkblue; margin-left:5px">The Two Towers</span>
			<span style="color:darkgreen; margin-left:5px">The Return of the King</span>
		</h4>
			<div class='progress progress-striped active'>
				<div class='progress-bar progress-bar-darkred' style='width:<?php echo $temp["The Fellowship of the Ring"]?>%'>
				<?php echo $temp["The Fellowship of the Ring"]?></div>
				
				<div class='progress-bar progress-bar-darkblue' style='width:<?php echo $temp["The Two Towers"]?>%'>
				<?php echo $temp["The Two Towers"]?></div>
				
				<div class='progress-bar progress-bar-darkgreen' style='width:<?php echo $temp["The Return of the King"]?>%'>
				<?php echo $temp["The Return of the King"]?></div>
			</div>
		</div>
	</div>
	
	<footer><a href="../homepage/homepage.html" style="color:white">Homepage</a></footer>
	
</body>
</html>

