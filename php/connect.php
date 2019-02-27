<?php
    
$user = 'root';
$pass = '';
$db = 'usersdb';
$conn = new mysqli('localhost', $user, $pass, $db) or die("Unable to connect");

$userName = $_REQUEST["username"];
$password = $_REQUEST["password"];
$firstName = $_REQUEST["password"];
$lastName = $_REQUEST["lastName"];
$email = $_REQUEST["email"];

$sql = "INSERT INTO users (username, pass, firstname, lastname, email)
Values ('{$userName}', '{$password}', '{$firstName}', '{$lastName}', '{$email}')";

if ($conn->query($sql) === TRUE) {
    echo "User created successfully<br><br>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}


?>