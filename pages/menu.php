<?php
// Start the session
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Autograder</title>
    <link rel="stylesheet" href="../css/style.css">
</head>
<header>
    <nav>
        <ul style="list-style-type: none;">
            <li>
                <a href="coding.php"><button id="b1" type="button">Start Coding!</button></a> 
            </li>
            <li>
                <a href="login.php"><button id="b1" type="button">log out</button></a> 
            </li>
        </ul>
    </nav>
</header>
<body>
    <div style="text-align: center">
        <h2>
            <span style="text-align: center; color:  rgb(215, 186, 100)">
                <?php
                    echo "Hello " . $_SESSION["user"] . ".<br>";
                ?>
            </span>
        </h2>
        
    </div>
    
    

</body>
</html>