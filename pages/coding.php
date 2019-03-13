<?php
// Start the session
session_start();
 $user = $_SESSION["user"];
?>
<!DOCTYPE html>
<html lang="en">

<head>

    <script type="text/javascript">
        // Sets the username variable with php session variable
        var user = "<?php echo $user; ?>";
        var problem = 1;
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
        <!-- This is the start of the data fields for problem instructions 
             which is dynamically filled through AJAX calls to the server -->
        <div class="instructions" name="instructions">
            <h1 id="title">Title of Problem</h1>
            <section>
                <h2>Objective:</h2>
                <p id="objective">
                    Some text describing the learning objective.
                </p> 
            </section>
            <section>
                <h2>Task:</h2>
                <p id="task">
                    Some text describing the task.
                </p>
            </section>
            <section>
                <h2>Input Format:</h2>
                <p id="inputFormat">
                    Some text describing the input format.
                </p>
            </section>
            <section>
                <h2>Constraints:</h2>
                <p id="constraints">
                    Some text describing the constraints.
                </p>
            </section>
            <section>
                <h2>Output Format:</h2>
                <p id="outputFormat">
                    Some text describing the output format.
                </p>
            </section>
            <section>
                <h2>Sample Input:</h2>
                <p id="sampleInput">
                    A sample input.
                </p>
            </section>
            <section>
                <h2>Sample Output</h2>
                <p id="sampleOutput">
                    A sample output.
                </p>
            </section>
        </div>

        <!-- This is where the Monaco editor will be rendered -->
        <div class="leftCol">
            <div id="container"></div>
        </div>
        <!-- This is the debug text area which houses the PHP responses
             from compilation -->
        <div class="rightCol">
            <textarea readonly="readonly" class="codingArea" id="debug" rows="20" cols="30" placeholder="Debugging statements appear here"></textarea>
        </div>
        <div class="leftCol">
            <button id="runCode" type="button" onclick="sendCode(editor.getValue(),problem,user)">Run Your Code</button>
        </div>

        <!-- This is the various things needed for initializing the Monaco editor -->
        <script>var require = { paths: { 'vs': '../node_modules/monaco-editor/min/vs' } };</script>
        <script src="../node_modules/monaco-editor/min/vs/loader.js"></script>
        <script src="../node_modules/monaco-editor/min/vs/editor/editor.main.nls.js"></script>
        <script src="../node_modules/monaco-editor/min/vs/editor/editor.main.js"></script>
        
        <script>
            var editor = monaco.editor.create(document.getElementById('container'), {
                value: [
                    '#include <iostream>',
                    'using namespace std;',
                    '',
                    'int main(){',
                    '\t/* Enter Code Here */',
                    '\tcout<<"Hello world!\\n";',
                    'return 0;',
                    '}'
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
</html>