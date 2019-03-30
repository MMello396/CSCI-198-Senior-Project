var textEditor = editor;
var problem;

// function save() {
//     // get the value of the data
//     var value = window.editor.getValue()
//     saveValue(value);
// }

// function saveValue(){

// }

function updateProblem1(){
    if(problem != 1){
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
                textEditor.setValue("void MyArray::MySelectionSort()\{\n\t/* ENTER CODE HERE */\n\n}");
                problem = 1;
            }
        }
        xhttp.open("POST", "../problemFiles/problem1.txt", true);
        xhttp.send();  
    }
    
}

function updateProblem2(){
    if (problem != 2){
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
                textEditor.setValue("void MyArray::MySelectionSort()\{\n\t/* ENTER CODE HERE */\n\n}");
                problem = 2;
            }
        }
        xhttp.open("POST", "../problemFiles/problem2.txt", true);
        xhttp.send();
    }
    
}

function updateProblem3(){
    alert("Problem not made yet... check back later.");
    problem = 3;
}

function updateProblem4(){
    alert("Problem not made yet... check back later.");
    problem = 4;
}

function updateProblem5(){
    alert("Problem not made yet... check back later.");
    problem = 5;
}

function updateProblem6(){
    alert("Problem not made yet... check back later.");
    problem = 6;
}

function updateProblem7(){
    alert("Problem not made yet... check back later.");
    problem = 7;
}

function updateProblem8(){
    alert("Problem not made yet... check back later.");
    problem = 8;
}