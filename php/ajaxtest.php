<?php  
    // Grabs the code from the xmlHTTPrequest variable named code
    // Note: (had to use JS encodeURIcomponent to get it to pass the string correctly)
    $sCode = $_REQUEST["code"];

    // hard coded username for development without user system built yet
    $userName = "user1";
    $userFile = "userfile.cpp";
    $userPath = "{$userName}/{$userFile}";

    // Sets the path for the files to be grabbed from
    // for compilation.
    
    // needs to determine if path exists for user already
    if(!is_dir("{$userName}tmp")){
        echo "making a temp dir";
        mkdir("{$userName}tmp");
    }

    // TODO: need to get a way of dynamically determining
    // file name by user. This would eliminate the issue 
    // that I forsee having multiple people compiling at
    // the same time with overwrite issues and the like.
    $fileName = "{$userName}";
    
    // Creates a file if it doesn't already
    // exist and writes the contents of a 
    // variable to the file, then closes the
    // file stream.

    // Having an issue with permissions... Need to do more research
    chdir("{$userName}tmp");
    $sourceFile = fopen($fileName, "w") or die("Unable to open file!");
    
    // Checking some of the permissions for directories
    echo "**** Directory Permissions for /tmp ****\n";
    echo substr(sprintf('%o', fileperms('/tmp')), -4) . "\n\n";

    echo "**** Directory Permissions for php/user ****\n";
    echo substr(sprintf('%o', fileperms(getcwd())), -4) . "\n\n";

    echo "**** File Owner Information ****\n";
    print_r(posix_getpwuid(fileowner($filePath))) . "\n\n";
    echo "**** End File Owner Information ****\n";

    // Write the source code passed from server
    // to a variable and then create a file and
    // fill it with the contents.
    $textToWrite = $sCode;
    fwrite($sourceFile, $textToWrite);
    
    // Use a system call to call the g++ compiler
    // with a specific name for the outputted 
    // compiled file on success or the errors 
    // output and compile failure.
    // $compileCall = "{$compilerPath} -o {$fileName} {$filePath} 2>&1";
    $compileCall = "g++ -o {$fileName} {$userFile} 2>&1";

    echo "\n**** System Call ****\n";
    echo $compileCall . "\n\n";
        
    // Compiles the program and returns the results
    // to the variable $output. The current returned
    // result is 0, and an executible is created
    $output = system($compileCall, $result);

    // Note: Here are options for g++ compilation that can be used in different cases
    // -g               == turn on debugging (so GDB gives more friendly output)
    // -Wall            == turns on most warnings
    // -O or -O2        == turn on optimizations
    // -o <name>        == name of the output file
    // -c               == output an object file (.o)
    // -I<include path> == specify an include directory
    // -L<library path> == specify a lib directory
    // -l<library>      == link with library lib<library>.a
    
    
    
    // Outputs the errors of compilation to the
    // debug screen if compilation fails.
    if ($result == 1) echo $output;

    // close file after compilation is complete
    // and file output is sent back to client
    fclose($sourceFile);

    // TODO: need to make code for grabbing the path after compilation and dynamically creating and grabbing that path
    exec("{$fileName}.exe", $returnedResult);
    echo "\n\n**** Executable Result Output ****\n";
    foreach($returnedResult as $line){
        echo $line;
        echo "\n";
    }
    
?>