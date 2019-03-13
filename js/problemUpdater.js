function updateProblem1(){
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
            var parsedProblem = JSON.parse(this.responseText);
            document.getElementById("title").innerHTML = parsedProblem.title;
            document.getElementById("objective").innerHTML = parsedProblem.objective;
            document.getElementById("task").innerHTML = parsedProblem.task;
            document.getElementById("inputFormat").innerHTML = parsedProblem.inputFormat;
            document.getElementById("constraints").innerHTML = parsedProblem.constraints;
            document.getElementById("outputFormat").innerHTML = parsedProblem.outputFormat;
            document.getElementById("sampleInput").innerHTML = parsedProblem.sampleInput;
            document.getElementById("sampleOutput").innerHTML = parsedProblem.sampleOutput;
        }
    }
    xhttp.open("POST", "../problemFiles/problem1.txt", true);
    xhttp.send();
}

function updateProblem2(){
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
            var parsedProblem = JSON.parse(this.responseText);
            document.getElementById("title").innerHTML = parsedProblem.title;
            document.getElementById("objective").innerHTML = parsedProblem.objective;
            document.getElementById("task").innerHTML = parsedProblem.task;
            document.getElementById("inputFormat").innerHTML = parsedProblem.inputFormat;
            document.getElementById("constraints").innerHTML = parsedProblem.constraints;
            document.getElementById("outputFormat").innerHTML = parsedProblem.outputFormat;
            document.getElementById("sampleInput").innerHTML = parsedProblem.sampleInput;
            document.getElementById("sampleOutput").innerHTML = parsedProblem.sampleOutput;
        }
    }
    xhttp.open("POST", "../problemFiles/problem2.txt", true);
    xhttp.send();
}

function updateProblem3(){
    alert("Problem not made yet... check back later.");
}

function updateProblem4(){
    alert("Problem not made yet... check back later.");
}

function updateProblem5(){
    alert("Problem not made yet... check back later.");
}

function updateProblem6(){
    alert("Problem not made yet... check back later.");
}

function updateProblem7(){
    alert("Problem not made yet... check back later.");
}

function updateProblem8(){
    alert("Problem not made yet... check back later.");
}