<?php
// Start the session
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Autograder</title>
    <link rel="stylesheet" type="text/css" href="../css/style.css">
</head>
<header>

</header>
<body>

    <h1 id="title" style="text-align: center">Autograder</h1>
    
    <div id="errors" style="color: #f00000; text-align: center; font-size: 14pt"></div>
    <div class="button">

        <form id="myform" autocomplete="on">
  
            <input type="text" id="uName" name="username" placeholder="Username"><br><br>
  
            <input type="password" id="pass" name="password" placeholder="Password">
  
        </form>

        <button id="b1" type="button" onclick="attemptLogin()">Login</button>
        <button id="b2" type="button" onclick="newUser()">New User</button>

    </div>
    
</body>
<footer>

</footer>
<script src="../js/login.js" charset="utf-8"></script>
</html>