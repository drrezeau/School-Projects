<?php

$myFile = fopen("assign13.txt", "a") or die("Unable to open File!");
$temp = $_GET["performanceType"];
fwrite($myFile,"<performanceType>" . $temp . "</performanceType>\n");
fwrite($myFile, "<student1FirstName>" . $_GET["student1FirstName"]
       . "</student1FirstName>\n");
fwrite($myFile, "<student1LastName>" . $_GET["student1LastName"]
       . "</student1LastName>\n");
if ($_GET["student2FirstName"] != "")
{
   fwrite($myFile, "<student2FirstName>" . $_GET["student2FirstName"]
       . "</student2FirstName>\n");
   fwrite($myFile, "<student2LastName>" . $_GET["student2LastName"]
       . "</student2LastName>\n");
}
   
fwrite($myFile, "<skill>" . $_GET["skill"] . "</skill>\n");
fwrite($myFile, "<instrument>" . $_GET["instrument"] . "</instrument>\n");
fwrite($myFile, "<location>" . $_GET["location"] . "</location>\n");
fwrite($myFile, "<room>" . $_GET["room"] . "</room>\n");
fwrite($myFile, "<time>" . $_GET["time"] . "</time>\n\n");

fclose($myFile);
?>
