<?php
header("Content-type=text/html");
?>

<html>
  <head>
    <link rel="stylesheet" type="text/css" href="assignments/Business Layout.css" />
    <title> Kanga Order Confirmed</title>
  </head>

  <body>
    <header>
      <?php
        print "<h1>Kanga's Australian Goods</h1>";
        print "<h3> G'Day Mate!</h3>";
      ?>
    </header>
    <?php
      if (isset($_GET["confirm"]))
        print "<p>Order Confirmed. <br /> Have a nice Day.</p>";
      else if (isset($_GET["cancel"]))
        print "<p>Order Canceled. <br /> Have a nice Day.</p>";
    ?>


    <footer>
      <div style="text-align:right"><a href="assign02.html" style="color:white" > Back </a></div>
    </footer>
  </body>
</html>