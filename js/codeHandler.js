// An event listener for resizing the Monaco text editor 
window.addEventListener("resize", function(){
    this.editor.layout();
});

function sendCode(code,problem,user){
    // Reset debug window
    document.getElementById("debug").innerHTML = "";

    // Start timer for response
    var timeout = setTimeout(kill,3000);

    // Send code
    debugCall(code,problem,user,timeout);
}

function kill(){
    killProgram(user);
}

function debugCall(codeValue,problem,user,timeout){    
    // Use AJAX to send source code to server as a string
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        // On ready state change 4 the AJAX request will update the debug field with
        // the returned message and clear the timeout timer.
        if (this.readyState == 4 && this.status == 200){   
            var msg = this.responseText;
            document.getElementById("debug").innerText = msg;
            clearTimeout(timeout);
            
            // Various statistics will be gathered here
            // Increment compilation counter
            incCompileCounter();

            // If errors are present in the response
            var errors = (msg.match(/error/g) || []).length;
            errorCount += errors;
            updateErrorCounter();
        }

       
    }
    xhttp.open("POST", "../php/codeRun.php?code="+encodeURIComponent(codeValue)+"&problem="+encodeURIComponent(problem)+"&username="+encodeURIComponent(user), true);
    xhttp.send();
}

function killProgram(user){
    // Use AJAX to send kill request to a PHP script after timeout
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
            // alert("Execution stopped: Timeout occured");
            document.getElementById("debug").innerHTML = "Execution stopped: Timeout occured";
        }
    }
    xhttp.open("POST", "../php/killProgram.php?username="+ encodeURIComponent(user), true);
    xhttp.send();
}