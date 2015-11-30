<?xml version="1.0" encoding="utf-8"?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
     "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" >


<html xmlns = "http://www.w3.org/1999/xhtml">
     <head>
     <title> PHP Test</title>
     <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
     <script>
     $(document).ready(function(){
           $("p").dblclick(function(){
                 $(this).css("background-color","gold");
              });
        });
</script>

     </head>

     <body>
     <h1> This is the example for class </h1>
     
<p style="color:red; background-color:blue">
     <?php

     for($i = 0; $i < 5; $i++)
     print "Hello" . $i . "<br>";
     for ($i = 100; $i < 200; $i +=25)
        print'<p style="font-size:'.$i.'%"> Hello <br></p>';
     ?>
</p>
<button>Change Color</button>
</body>
</html>
