var compileCount = 0;
var errorCount = 0;
var compileDisplay = document.getElementById('compiles');
var errorDisplay = document.getElementById('errors');

function startTimer(display) {
    var timer = 0, minutes, seconds;
    setInterval(function () {
        timer++;
        minutes = parseInt(timer / 60, 10)
        seconds = parseInt(timer % 60, 10);

        minutes = minutes < 10 ? "0" + minutes : minutes;
        seconds = seconds < 10 ? "0" + seconds : seconds;

        display.textContent = minutes + ":" + seconds;

    }, 1000);
}

window.onload = function () {
        display = document.getElementById("time");
    startTimer(display);
};

function incCompileCounter(){
    compileCount += 1;
    updateDisplay();
}

function updateErrorCounter(){
    updateDisplay();
}

function updateDisplay(){
    compileDisplay.innerText = compileCount;
    errorDisplay.innerText = errorCount;
}