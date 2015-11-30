<?php

$myfile = fopen("new.txt", "w") or die("Unable to open.");
$text = "changing the lines of code\n";
fwrite($myfile, $text);
$text= "new line of writing\n";
fwrite($myfile, $text);
fclose($myfile);

echo "done";
?>