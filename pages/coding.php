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
<header>
    <!-- This is the navigation bar to navigate the site. Would like to update to
         a more fluid and robust nav -->
    <nav>
        <ul style="list-style-type: none;">
            <li>
                <a href="menu.php"><button id="menu" type="button">Menu</button></a>
            </li>
            <li>
                <button id="p1" type="button" onclick="updateProblem1()">Problem 1</button>
            </li>
            <li>
                <button id="p2" type="button" onclick="updateProblem2()">Problem 2</button>
            </li>
            <li>
                <button id="p3" type="button" onclick="updateProblem3()">Problem 3</button>
            </li>
            <li>
                <button id="p4" type="button" onclick="updateProblem4()">Problem 4</button>
            </li>
            <li>
                <button id="p5" type="button" onclick="updateProblem5()">Problem 5</button>
            </li>
            <li>
                <button id="p6" type="button" onclick="updateProblem6()">Problem 6</button>
            </li>
            <li>
                <button id="p7" type="button" onclick="updateProblem7()">Problem 7</button>
            </li>
            <li>
                <button id="p8" type="button" onclick="updateProblem8()">Problem 8</button>
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
                    '/* Enter Code Here */',
                    'cout<<"Hello world!\\n";' ,
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

</html>