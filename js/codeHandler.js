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