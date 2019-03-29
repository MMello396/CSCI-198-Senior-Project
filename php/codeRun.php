<?php
    // Grabs the code and username from the xmlHTTPrequest variable named code
    // Note: (had to use JS encodeURIcomponent to get it to pass the string correctly)
    $sCode = $_REQUEST["code"];
    $uName = $_REQUEST["username"];
    $problem = $_REQUEST["problem"];    

    // Dynamic setting of file paths and names for users
    $userName = $uName; 
    $userFile = "userfile.cpp";
    $fileName = "{$userName}";
    $includeDir = "../../files";

    // Sets the path for the files to be grabbed by this
    // script for current user. Needs to determine if path
    // exists for user already
    if(!is_dir("{$userName}tmp")){
        mkdir("{$userName}tmp");
    }
    
    // Creates a file if it doesn't already
    // exist and writes the contents of a 
    // variable to the file, then closes the
    // file stream.
    chdir("{$userName}tmp");
    $sourceFile = fopen($userFile, "w") or die("Unable to open file!");
    
    // Write the source code passed from server
    // to a variable
    $textToWrite = $sCode;
    
    // TODO: depending on problem being worked
    // choose the right file to append to user
    // code provided in "textToWrite"

    $part1 = file_get_contents("{$includeDir}/main.cpp");
    $part2 = $textToWrite;

    fwrite($sourceFile, $part1);
    fwrite($sourceFile, $part2);

    // Use a system call to call the g++ compiler
    // with a specific name for the outputted 
    // compiled file on success or the errors 
    // output and compile failure.
    $compileCall = "g++ -o {$fileName} {$userFile} 2>&1";
        
    // Compiles the program and returns the results
    // to the variable $output. The current returned
    // result is 0, and an executible is created
    $output = system($compileCall, $result);

    $command = "{$fileName}.exe";
    
    // Outputs the errors of compilation to the
    // debug screen if compilation fails. Returns
    // resulting execution is succeeds
    if ($result == 1) {
      echo $output;
    }
    else{
      exec($command, $result);
    }

    foreach($result as $line){	
      echo $line;	
      echo "\n";	
    }

    // close file after compilation is complete
    // and file output is sent back to client
    fclose($sourceFile);
?>