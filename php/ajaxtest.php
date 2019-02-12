<?php  
    // Path to compiler needs to be set inorder
    // in order for the server to be able to use
    // it. Something about having different search
    // paths.

    // Need to be able to detemine compiler path 
    // dynamically somehow..
    
    // $compilerPath = "C:/cygwin64/bin/g++"; // For Desktop
    // $compilerPath = ""; // For MAC
    // $compiler = file_exists($compilerPath);
    // if ($compiler == False) echo "True";

    // Grabs the code from the xmlHTTPrequest variable named code
    // Note: (had to use JS encodeURIcomponent to get it to pass the string correctly)
    $sCode = $_REQUEST["code"];

    // Sets the path for the files to be grabbed from
    // for compilation.
    $path = "../files/";
    $file = "testfile.cpp";
    $filePath = "{$path}{$file}";

    // TODO: need to get a way of dynamically determining
    // file name by user. This would eliminate the issue 
    // that I forsee having multiple people compiling at
    // the same time with overwrite issues and the like.
    $fileName = "helloworld";
    
    // Creates a file if it doesn't already
    // exist and writes the contents of a 
    // variable to the file, then closes the
    // file stream.
    $sourceFile = fopen($filePath, "w") or die("Unable to open file!");
    
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
    $compileCall = "g++ -o {$fileName} {$filePath} 2>&1";
    // echo $compileCall . "\n\n";
    
    // Note: Here are options for g++ compilation that can be used in different cases
    // -g               == turn on debugging (so GDB gives more friendly output)
    // -Wall            == turns on most warnings
    // -O or -O2        == turn on optimizations
    // -o <name>        == name of the output file
    // -c               == output an object file (.o)
    // -I<include path> == specify an include directory
    // -L<library path> == specify a lib directory
    // -l<library>      == link with library lib<library>.a
    
    // I think this compiles the program. The current
    // returned result is 0, and an executible is 
    // created
    // echo exec($compileCall);
    $output = system($compileCall, $result);
    
    // Outputs the errors of compilation to the
    // debug screen if compilation fails.
    if ($result == 1) echo $output;

    // close file after compilation is complete
    // and file output is sent back to client
    fclose($sourceFile);

    // TODO: need to make code for grabbing the path after compilation and dynamically creating and grabbing that path
    exec("{$fileName}.exe", $returnedResult);
    foreach($returnedResult as $line){
        echo $line;
        echo "\n";
    }
    
?>