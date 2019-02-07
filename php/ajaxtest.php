<?php  

    // not correctly grabbing the variable, need to research _GET...
    $sCode = $_REQUEST["code"];
    echo $sCode;

    // *** testing opening and writing to files ***
    // creates a file if it doesn't already
    // exist and writes the contents of a 
    // variable to the file, then closes the
    // file stream.
    $sourceFile = fopen("../testfiles/testfile.txt", "w") or die("Unable to open file!");
    
    
    // need to write the source code passed from server to this variable.
    // $textToWrite = "#include <iostream>\n\nint main(){\n\n\tcout<<\"Hello world!\"<<endl;\n\n}";
    $textToWrite = $sCode;


    fwrite($sourceFile, $textToWrite);
    fclose($sourceFile);

    // testing variables
    $x = 501;

    // *** testing opening and reading a file into a variable for printing to the debug text field ***
    $output = fopen("../testfiles/testfile.txt", "r") or die("Unable to open file!");
    $filename = "../testfiles/testfile.txt";
    // echo fread($output, filesize($filename));
    fclose($output);

    // echo "Here is the value of a variable created in the script - " . $x;
    // echo $code;
    // echo "Hello World!"
?>