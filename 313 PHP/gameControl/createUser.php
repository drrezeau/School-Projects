<!DOCTYPE html>
<!--The form page to let people create a new user
It will check the username and make sure that both
passwords match so the user does not accidently type
the wrong password-->


<html>
    <head>
       <title>Create User</title>
        <link rel="stylesheet" href="bootstrap-3.3.2-dist/css/bootstrap.css" />
        <link rel="stylesheet" href="Layout.css" />
  		  <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>

        
         <script>
				var taken = false;
				var PSWD = false;
				var checked = false;
           function checkPSWD()
            {
               var password = document.getElementById("password").value;
               var pswd = document.getElementById("pswd").value;
               if (password != pswd)
               {
                document.getElementById("wrongPSWD").innerHTML = "Passwords do not match.";
						document.user.submit.type = "button";
						PSWD = false;
               }
               else
               {
                 document.getElementById("wrongPSWD").innerHTML = "";
						document.user.submit.type = "submit";
						PSWD = true;

               }
            }
             
				
				$(document).ready(function(){
				$("button").click(function() {
					$.post("checkUser.php",
							 {
								user: $("#userName").val()
							 },
							 function(data) {
						checked = true;
						if(data == "true")
						{
							alert("Username is Available");
							taken = false;
						}
						else {
							alert("Username is taken")
							taken = true;
						}
					});
				});
			});
				
				function validate() {
					if(!checked)
					{
						alert("Have not checked userName");
						return false;
					}
					if(taken)
					{
						alert("Username is Taken");
						return false;
					}
					if(!PSWD)
						return false;
				}
       </script>
    </head>
    <body>
        <header>
            <h1>Create a new User</h1>
            <div><a href="login.php">Back</a></div>
        </header>
        
           <form action="user.php" onsubmit="return validate()" method="POST" name="user" >
              <div ><input type="text" id="userName" name="user" placeholder="Username" required/>
              <span><button type="button">Check</button></span></div> <br />
              <div ><input type="password" id="password" name="pswd" placeholder="Password" value="" required/></div> <br />
              <div ><input type="password" id="pswd" placeholder="Re-type Password" 
              onchange="checkPSWD()" value="" required/></div> <div id="wrongPSWD"></div> <br />
               
              <div ><input type="text" placeholder="First Name" name="first" required/></div> <br />
              <div ><input type="text" placeholder="Last Name" name="last" required/></div> <br />
              <div ><input type="email" placeholder="Email" name="email" required/></div>
              <input type="submit" value = "Submit" name="submit"  /><span style="margin-left:20px">
              <input type="reset" value="Reset" /></span>
        </form>
    </body>
</html>