<?php
header("Content-type=text/html");
?>


<html>
  <head>
    <title> Kanga Confirmation Page</title>
    <link rel="stylesheet" type="text/css" href="assignments/Business Layout.css" />
  </head>

  <body>
    <header>
      <?php
        print "<h1>Kanga's Australian Goods</h1>\n";
        print "<h3>G'Day Mate!</h3>\n";
      ?>
    </header>
    <h2 style="text-align:center"> Confirmation Page</h2>
    <p style="border:solid; width:350px; height:auto; margin:auto; margin-top:5px; padding:5px">
        
    <?php
      echo "Name: " . $_GET["firstname"] . ' ' . $_GET["lastname"] . "<br />\n";
      echo "Address: " . $_GET["street"] . "<br />" . $_GET["city"] . ", " . $_GET["state"] . ". " . $_GET["zip"] . "<br />\n";
      echo "Phone: " . $_GET["phone"] . "<br /> <br />\n";
      echo "Card Type: " . $_GET["card"] . "<br />\n";
      echo "Card Number: " . $_GET["card#"] . "<br />\n";
      echo "Card Expire Date: <br />" . $_GET["expMonth"] . ' ' . $_GET["expYear"] . "<br />\n";

      echo "<br /> List of Items: <br />\n";
      $total = 0;
      if (isset($_GET["item1"]))
      {
        echo "Tim Tams $" . $_GET["item1"] . "<br />\n";
        $total += $_GET["item1"];
      }

      if (isset($_GET["item2"]))
      {
        echo "An Australian friend $" . $_GET["item2"] . "<br />\n";
        $total += $_GET["item2"];
      }

      if (isset($_GET["item3"]))
      {
        echo "Ginger Beer $" . $_GET["item3"] . "<br />\n";
        $total += $_GET["item3"];
      }

      if (isset($_GET["item4"]))
      {
        echo "A Kangaroo $" .$_GET["item4"] . "<br />\n";
        $total += $_GET["item4"];
      }

      if (isset($_GET["item5"]))
      {
       echo "A Koala $" . $_GET["item5"] . "<br />\n";
       $total += $_GET["item5"];
      }

      echo "<br /> Total: " . $total . "<br />\n";
    ?>

    <form action="assign11_a.php">
      <p>
        <input type="submit" name="confirm" style="font-size:115%" value="Confirm" />
        <input type="submit" name="cancel" style="font-size:115%" value="Cancel" />
      </p>
    </form>
  </p>

  </body>
</html>