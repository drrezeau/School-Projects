<?php
//for ($i = 0; $i < 5; $i++)
   mail($_GET['to'], $_GET['subject'], $_GET['body'], "From: ".$_GET['from']);
?>