var submitButton = document.getElementById("submit");
var b1 = document.getElementById("b1");
var b2 = document.getElementById("b2");
var form = document.getElementById("myform");

// displays the form for creating a login
function newUser(){

    var fnField = document.createElement("input");
    fnField.setAttribute("type","text");
    fnField.setAttribute("name", "firstname");
    fnField.setAttribute("placeholder", "First Name");
    fnField.setAttribute("id","fName");

    var lnField = document.createElement("input");
    lnField.setAttribute("type","text");
    lnField.setAttribute("name", "lastname");
    lnField.setAttribute("placeholder", "Last Name");
    lnField.setAttribute("id","lName");

    var emailField = document.createElement("input");
    emailField.setAttribute("type","text");
    emailField.setAttribute("name", "email");
    emailField.setAttribute("placeholder", "Email");
    emailField.setAttribute("id","email");
    
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(fnField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(lnField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(emailField);

    newUserButtons();
}

// displays the login form
function loginButtons(){
    var unField = document.createElement("input");
    unField.setAttribute("type", "text");
    unField.setAttribute("name", "username");
    unField.setAttribute("placeholder", "Username");
    unField.setAttribute("id","uName");

    var pwField = document.createElement("input");
    pwField.setAttribute("type", "text");
    pwField.setAttribute("name", "password");
    pwField.setAttribute("placeholder", "Password");
    pwField.setAttribute("id","pass");

    form.append(unField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(pwField);

    b1.setAttribute("onclick", "attemptLogin()");
    b1.innerText = "Login"

    b2.setAttribute("onclick", "newUser()");
    b2.innerText = "New User";
}

function newUserButtons(){
    b1.setAttribute("onclick", "submit()");
    b1.innerText = "Submit";

    b2.setAttribute("onclick", "loginButtons()");
    b2.innerText = "Cancel";
}

// checks for user in database
function attemptLogin(){
    
    var user = document.getElementById("uName").value;

    var pass = document.getElementById("pass").value;

    alert(user + "\n" + pass);
    checkUser(user, pass);

    // check if user is in the database
    var userPresent = true; // php check here?

    // if yes, send to menu
    if (userPresent){
        location.href = 'menu.html';
    }
    else {

    }
}

// creates user in database
function submit(){
    var user = document.getElementById("uName").value;
    var pass = document.getElementById("pass").value;
    var fName = document.getElementById("fName").value;
    var lName = document.getElementById("lName").value;
    var email = document.getElementById("email").value;

    // Make an AJAX call to check if username is taken and returns success or failure
    checkAvail(user,pass,fName,lName,email);
}

function checkAvail(user,pass,fName,lName,email){    

    // Use AJAX to send source code to server as a string
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
            form.innerHTML = this.responseText;
            loginButtons();
        }
    }
    xhttp.open("POST", "../php/connect.php?username="+encodeURIComponent(user)+"&password="+encodeURIComponent(pass)+"&firstName="+encodeURIComponent(fName)+"&lastName="+encodeURIComponent(lName)+"&email="+encodeURIComponent(email), true);
    xhttp.send();
}

function checkUser(user, password){    

    // Use AJAX to send source code to server as a string
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
            form.innerHTML = this.responseText;
        }
    }
    xhttp.open("POST", "../php/connect.php?username="+encodeURIComponent(user)+"&password="+encodeURIComponent(password), true);
    xhttp.send();
}