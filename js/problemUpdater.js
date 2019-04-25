var textEditor = editor;
var problem;
function save() {

    // get the data from the various information panels
    var savedTime = document.getElementById("time").innerText;
    var savedNumComps = compileDisplay.innerText;
    var savedNumErrors = errorDisplay.innerText;
    saveInfo(savedTime, savedNumComps, savedNumErrors);

    // get the code from the editor
    var value = window.editor.getValue()
    saveValue(value);
}

function saveInfo(time, numComps, numErrors){
    var saveState = (time, numComps, numErrors);
}

function saveValue(value){
    var saveState = value;
}

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
                textEditor.setValue("void MyArray::MySelectionSort()\{\n\t/*Use SwapIndex(x,y) to swap values of array elements a[x] and a[y]*/\n\t/* ENTER CODE HERE */\n\n}");
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
                textEditor.setValue("void MyDCList::MyInsertHead(int x)\{\n\t/*node Constructor: Node(value, next, previous)*/\n\t/* ENTER CODE HERE */\n\n}");
                problem = 2;
            }
        }
        xhttp.open("POST", "../problemFiles/problem2.txt", true);
        xhttp.send();
    }
    
}

function updateProblem3(){
    if (problem != 3){
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
                textEditor.setValue("void MyDCList::MyDeleteHead()\{\n\t/*node attributes: value of node; next node pointer; previous node pointer*/\n\t/* ENTER CODE HERE */\n\n}");
                problem = 3;
            }
        }
        xhttp.open("POST", "../problemFiles/problem3.txt", true);
        xhttp.send();
    }
}