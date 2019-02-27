<?php
    /**
 * Execute a command and return it's output. Either wait until the command exits or the timeout has expired.
 *
 * @param string $cmd     Command to execute.
 * @param number $timeout Timeout in seconds.
 * @return string Output of the command.
 * @throws \Exception
 */
function exec_timeout($cmd, $timeout) {
    // File descriptors passed to the process.
    $descriptors = array(
      0 => array('pipe', 'r'),  // stdin
      1 => array('pipe', 'w'),  // stdout
      2 => array('pipe', 'w')   // stderr
    );
  
    // Start the process.
    $process = proc_open($cmd, $descriptors, $pipes);
  
    if (!is_resource($process)) {
      throw new \Exception('Could not execute process');
    }
  
    // Set the stdout stream to none-blocking.
    stream_set_blocking($pipes[1], 0);
  
    // Turn the timeout into microseconds.
    $timeout = $timeout * 1000000;
    
    // Output buffer.
    $buffer = '';

    // Debugging timeout
    // echo "Time to run: {$timeout} Microseconds\n";

    // While we have time to wait.
    while ($timeout > 0) {
        $start = microtime(true);
  
        // Wait until we have output or the timer expired.
        $read  = array($pipes[1]);
        $other = array();
        stream_select($read, $other, $other, 0, $timeout);
  
        // Get the status of the process.
        // Do this before we read from the stream,
        // this way we can't lose the last bit of output if the process dies between these functions.
        $status = proc_get_status($process);

        // Read the contents from the buffer.
        // This function will always return immediately as the stream is none-blocking.
        $buffer .= stream_get_contents($pipes[1]);

        if (!$status['running']) {
            // Break from this loop if the process exited before the timeout.
            break;
        }
    
        $elapsed = (microtime(true) - $start) * 1000000;
        $timeout -= $elapsed;
    }
  
    // Check if there were any errors.
    $errors = stream_get_contents($pipes[2]);
  
    if (!empty($errors)) {
      throw new \Exception($errors);
    }

    // Error message display for timeout
    if($timeout < 0){
        echo "Your program terminated due to timeout.";
    }
    
    // Kill the process in case the timeout expired and it's still running.
    // If the process already exited this won't do anything.
    proc_terminate($process, 9);
  
    // Close all streams.
    fclose($pipes[0]); //stdin
    fclose($pipes[1]); //stdout
    fclose($pipes[2]); //stderr
  
    proc_close($process);
  
    return $buffer;
  }

    // Grabs the code and username from the xmlHTTPrequest variable named code
    // Note: (had to use JS encodeURIcomponent to get it to pass the string correctly)
    $sCode = $_REQUEST["code"];
    // $uName = $_REQUEST["username"];
    $time = 2;

    // hard coded username for development without user system built yet
    $userName = "user1"; // eventually needs to be $uName
    $userFile = "userfile.cpp";
    $fileName = "{$userName}";

    // Sets the path for the files to be grabbed by this
    // script for current user. Needs to determine if path
    // exists for user already
    if(!is_dir("{$userName}tmp")){
        echo "making a temp dir";
        mkdir("{$userName}tmp");
    }
    
    // Creates a file if it doesn't already
    // exist and writes the contents of a 
    // variable to the file, then closes the
    // file stream.
    chdir("{$userName}tmp");
    $sourceFile = fopen($userFile, "w") or die("Unable to open file!");
    
    // Write the source code passed from server
    // to a variable and then create a file and
    // fill it with the contents.
    $textToWrite = $sCode;
    fwrite($sourceFile, $textToWrite);
    
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
      echo exec_timeout($command, $time);
    }

    // close file after compilation is complete
    // and file output is sent back to client
    fclose($sourceFile);
?>