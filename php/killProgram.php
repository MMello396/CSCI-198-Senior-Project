<?php
    // User whose task needs to be killed
    $uName = $_REQUEST["username"];

    // Task to kill
    $task = $uName;

    // Sets pattern for preg_match pattern matching
    $kill_pattern = '~('. $task .')\.exe~i';

    // Get the current task list
    $task_list = array();
    exec("tasklist 2>NUL", $task_list);

    foreach ($task_list AS $task_line)
    {
        if (preg_match($kill_pattern, $task_line, $out))
        {
            exec("taskkill /F /IM ".$out[1].".exe 2>NUL");
        }
    }
?>