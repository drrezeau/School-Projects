<?php

   mail("david.r.lambertson@gmail.com", "comment", $_GET['message'], "From: ".$_GET['name']);

?>