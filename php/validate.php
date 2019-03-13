<?php
    session_start();

    $user = 'root';
    $pass = '';
    $db = 'usersdb';
    $conn = mysqli_connect('localhost', $user, $pass, $db) or die("Unable to connect");

    $userName = $_REQUEST["username"];
    $password = $_REQUEST["password"];
    
    $sql = "SELECT username, pass FROM users WHERE username = '{$userName}' AND pass = '{$password}'";

    $result = mysqli_query($conn, $sql);
    // Run query and evaluate result
    if (mysqli_num_rows($result) == 1){
        $_SESSION["user"] = "{$userName}";
        echo "True";
    }else{
        echo "False";
    }
    
?>