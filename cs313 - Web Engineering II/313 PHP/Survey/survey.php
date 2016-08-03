<?php
session_start();
if ($_SESSION["sent"])
	header("Location:surveyDisplay.php");

$_SESSION["sent"] = true;

$temp = unserialize( file_get_contents("survey.txt"));

$character = $_POST["character"];
$battle = $_POST["battle"];
$fCharacter = $_POST["female"];
$movie = $_POST["movie"];



switch ($character) {
	
	case "Aragorn":
	$temp["Aragorn"]++;
	break;
	case "Gandalf":
	$temp["Gandalf"]++;
	break;
	case "Gollum":
	$temp["Gollum"]++;
	break;
	case "Saruman":
	$temp["Saruman"]++;
	break;
	case "Frodo":
	$temp["Frodo"]++;
	break;
	case "Sauron":
	$temp["Sauron"]++;
	break;
	case "Sam":
	$temp["Sam"]++;
	break;
	case "Legolas":
	$temp["Legolas"]++;
	break;
	case "Gimli":
	$temp["Gimli"]++;
	break;
}

switch ($battle) {
	
	case "Weather Top":
	$temp["Weather Top"]++;
	break;
	case "Helm's Deep":
	$temp["Helm's Deep"]++;
	break;
	case "Minas Tirith":
	$temp["Minas Tirith"]++;
	break;
	case "The Black Gate":
	$temp["The Black Gate"]++;
	break;
}

switch ($fCharacter) {
	
	case "Arwen":
	$temp["Arwen"]++;
	break;
	case "Eowyn":
	$temp["Eowyn"]++;
	break;
	case "Galadriel":
	$temp["Galadriel"]++;
	break;
}

switch ($movie) {
	
	case "The Fellowship of the Ring":
	$temp["The Fellowship of the Ring"]++;
	break;
	case "The Two Towers":
	$temp["The Two Towers"]++;
	break;
	case "The Return of the King":
	$temp["The Return of the King"]++;
	break;
}


	file_put_contents("survey.txt", serialize($temp));
	header("Location: surveyDisplay.php");
?>
