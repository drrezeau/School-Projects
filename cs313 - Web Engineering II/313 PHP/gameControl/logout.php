<?php

setcookie('user', "", time() - 3600);
setcookie('userId', "", time() -3600);
header("Location:homepage.php");

?>