<?php
session_start();
$array = array("Aragorn"=>0, "Gandalf"=>0, "Frodo"=>0, "Gollum"=>0, "Sauron"=>0, "Sam"=>0, "Saruman"=>0, "Legolas"=>0, "Gimli"=>0, "Weather Top"=>0, "Helm's Deep"=>0, "Minas Tirith"=>0, "The Black Gate"=>0, "Arwen"=>0, "Eowyn"=>0, "Galadriel"=>0, "The Fellowship of the Ring"=>0, "The Two Towers"=>0, "The Return of the King"=>0);


file_put_contents("survey.txt", serialize($array));

session_unset();
session_destroy();
header("Location: surveyForm.php");
?>