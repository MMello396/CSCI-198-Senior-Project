var probTitle = document.getElementById("title").innerHTML
var probObj = document.getElementById("objective").innerHTML
var probTask = document.getElementById("task").innerHTML
var probInputFormat = document.getElementById("inputFormat").innerHTML
var probConstraints = document.getElementById("constraints").innerHTML
var probOutputFormat = document.getElementById("outputFormat").innerHTML
var probSampleInput = document.getElementById("sampleInput").innerHTML
var probSampleOutput = document.getElementById("sampleOutput").innerHTML

function ajaxCall(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("debug").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "../testfiles/debug_test.txt", true);
    xhttp.send();
}

function updateProblem(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
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
    };
    xhttp.open("GET", "../testfiles/problem1.txt", true);
    xhttp.send();
}