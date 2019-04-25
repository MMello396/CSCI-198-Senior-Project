<?php
// Start the session
session_start();
 $user = $_SESSION["user"];
?>

<!DOCTYPE html>
<html lang="en">

<head>

    <!-- A simple initial script to set some global variables -->
    <script type="text/javascript">
        // Sets the username variable with php session variable
        var user = "<?php echo $user; ?>";
    </script>

    <title>Autograder</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
	<meta http-equiv="Content-Type" content="text/html;charset=utf-8" >
    <link rel="stylesheet" href="../css/style.css">
    <link rel="stylesheet" data-name="vs/editor/editor.main" href="../node_modules/monaco-editor/min/vs/editor/editor.main.css">

</head>

<!-- Styling for the loading animation -->
<style>
#loader {
    position: absolute;
    left: 50%;
    top: 50%;
    z-index: 1;
    width: 150px;
    height: 150px;
    margin: -75px 0 0 -75px;
    border: 16px solid #f3f3f3;
    border-radius: 50%;
    border-top: 16px solid #998811;
    width: 120px;
    height: 120px;
    -webkit-animation: spin 2s linear infinite;
    animation: spin 2s linear infinite;
}

/* .animate-slide_down {
  position: relative;
  -webkit-animation-name: animatefade;
  -webkit-animation-duration: 1s;
  animation-name: animatefade;
  animation-duration: 1s;
  animation-delay: 2s;
}

@keyframes animatefade { 
  from{ opacity:1 } 
  to{ opacity:0 }
} */

@keyframes spin {
  0% { transform: rotate(0deg); }
  100% { transform: rotate(360deg); }
}
</style>

<!-- A splash screen div that covers the screen until all elements are loaded -->
<div id="cover" class="animate-fade" style="width: 100%; height: 100%; background-color: #404040; position: fixed; z-index: 100;">
  <div id="loader"></div>
</div>
    
<header>
    <!-- This is the navigation bar to navigate the site. Would like to update to
         a more fluid and robust nav -->
    <nav>
        <ul style="list-style-type: none;">
            <li>
                <a href="menu.php"><button id="menu" type="button">Menu</button></a>
            </li>
            <li>
                <button id="p1" type="button" onclick="save();updateProblem1();">Selection Sort</button>
            </li>
            <li>
                <button id="p2" type="button" onclick="save();updateProblem2();">DCL Insertion </button>
            </li>
            <li>
                <button id="p3" type="button" onclick="save();updateProblem3();">DCL Deletion</button>
            </li>
        </ul>
    </nav>
</header>
<body>
    <div class="row">
        <!-- This is the start of the data fields for problem instructions 
        which is dynamically filled through AJAX calls to the server -->
        <div class="columnLeft2" style="padding: 1%;">
            <div class="row">
                <div class="column" style="padding: 1%;">
                    <h1 id="title"></h1>
                    <section>
                        <h2>Objective:</h2>
                        <p id="objective"></p> 
                    </section>
                    <section>
                        <h2>Task:</h2>
                        <p id="task"></p>
                    </section>
                    <section>
                        <h2>Input Format:</h2>
                        <p id="inputFormat"></p>
                    </section>
                </div>
                <div class="column" style="padding: 1%;">
                    <section>
                        <h2>Constraints:</h2>
                        <p id="constraints"></p>
                    </section>
                    <section>
                        <h2>Output Format:</h2>
                        <p id="outputFormat"></p>
                    </section>
                    <section>
                        <h2>Sample Input:</h2>
                        <p id="sampleInput"></p>
                    </section>
                    <section>
                        <h2>Sample Output</h2>
                        <p id="sampleOutput"></p>
                    </section>
                </div>
            </div>
            
        </div>

        <!-- This is the start of the information fields for the current problem 
             which is dynamically filled by javascript functions giving the user
             an idea of his progress and performance -->
        <div class="columnRight1" style="padding: 1%;">
            <!-- Timer -->
            <h1 id="timer">Time:</h1>
            <section>
                <h2 id="time">00:00</h2> 
            </section>
            <!-- Compile Counter -->
            <h1 id="compileCounter">Number of compilations:</h1>
            <section>
                <h2 id="compiles"></h2>
            </section>
            <!-- Error Counter -->
            <h1 id="errorCounter">Number of errors:</h1>
            <section>
                <h2 id="errors"></h2>
            </section>
            <div class="row">
                <div class="column">
                    <h2 id="compErrTitle">Compile Errors:</h2>
                    <section>
                        <h2 id="compErrors"></h2>
                    </section>
                </div>
                <div class="column">
                    <h2 id="logiErrTitle">Logic Errors:</h2>
                    <section>
                        <h2 id="logiErrors"></h2>
                    </section>
                </div>
            </div>
            
        </div>
    </div>
    <!-- Row containing the editor and debug panel -->
    <div class="row">
        <!-- This is where the Monaco editor will be rendered -->
        <div class="column">
            <div id="container"></div>
        </div>
        <!-- This is the debug text area which houses the PHP responses
             from compilation -->
        <div class="column">
        <div class="codingArea" id="debug">Debug Area</div>
        </div>
    </div>
    <!-- Row containing the button that sends code to server -->
    <div class="row">
        <div class="column">
            <button id="runCode" type="button" onclick="sendCode(editor.getValue(),problem,user)">Run Your Code</button>
        </div>
    </div>
        <!-- This is the various things needed for initializing the Monaco editor -->
        <script>var require = { paths: { 'vs': '../node_modules/monaco-editor/min/vs' } };</script>
        <script src="../node_modules/monaco-editor/min/vs/loader.js"></script>
        <script src="../node_modules/monaco-editor/min/vs/editor/editor.main.nls.js"></script>
        <script src="../node_modules/monaco-editor/min/vs/editor/editor.main.js"></script>
        
        <script>
            var editor = monaco.editor.create(document.getElementById('container'), {
                value: [
                
                ].join('\n'),
                language: 'cpp',
                fontSize: 16
            });
            monaco.editor.setTheme('vs-dark');
        </script>
        
</body>
<footer>
    <input type="hidden" name="mysession" id="mysession">   
</footer>
<script src="../js/codeHandler.js" charset="utf-8"></script>
<script src="../js/problemUpdater.js" charset="utf-8" onload="updateProblem1()"></script>
<script src="../js/infoPanels.js" charset="utf-8" onload="updateDisplay()"></script>

<!-- Script that disables the loading splash screen -->
<script src="../js/animate.js" charset="utf-8" onload="myFunction()"></script>
</html>