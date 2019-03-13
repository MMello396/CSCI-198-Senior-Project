// An event listener for resizing the Monaco text editor 
window.addEventListener("resize", function(){
    this.editor.layout();
});

function sendCode(code,user){
    // Reset debug window
    document.getElementById("debug").innerHTML = "";

    // Start timer for response
    var timeout = setTimeout(kill,3000);

    // Send code
    debugCall(code,user,timeout);
}

function kill(){
    killProgram(user);
}

function debugCall(codeValue,user,timeout){    
    // Use AJAX to send source code to server as a string
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){   
            document.getElementById("debug").innerHTML = this.responseText;
            clearTimeout(timeout);
        }
    }
    xhttp.open("POST", "../php/codeRun.php?code="+encodeURIComponent(codeValue)+"&username="+encodeURIComponent(user), true);
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