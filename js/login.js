var submitButton = document.getElementById("submit");
var b1 = document.getElementById("b1");
var b2 = document.getElementById("b2");
var form = document.getElementById("myform");

// displays the form for creating a login
function newUser(){

    // Clears the old form
    clearFields();

    // Building of new fields
    var unField = document.createElement("input");
    unField.setAttribute("type", "text");
    unField.setAttribute("name", "username");
    unField.setAttribute("placeholder", "Username");
    unField.setAttribute("id", "uName");

    var pwField = document.createElement("input");
    pwField.setAttribute("type", "password");
    pwField.setAttribute("name", "password");
    pwField.setAttribute("placeholder", "Password");
    pwField.setAttribute("id", "pass");

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
    
    // Builds the new form
    form.append(unField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(pwField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(fnField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(lnField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(emailField);

    // Button functionality change
    b1.setAttribute("onclick", "submit()");
    b1.innerText = "Submit";
    b2.setAttribute("onclick", "login()");
    b2.innerText = "Cancel";
}

// displays the login form
function login(){

    // Clears the old form
    clearFields();

    // Building of new fields
    var unField = document.createElement("input");
    unField.setAttribute("type", "text");
    unField.setAttribute("name", "username");
    unField.setAttribute("placeholder", "Username");
    unField.setAttribute("id","uName");

    var pwField = document.createElement("input");
    pwField.setAttribute("type", "password");
    pwField.setAttribute("name", "password");
    pwField.setAttribute("placeholder", "Password");
    pwField.setAttribute("id","pass");

    // Builds the new form
    form.append(unField);
    form.append(document.createElement("br"));
    form.append(document.createElement("br"));
    form.append(pwField);

    // Button functionality change
    b1.setAttribute("onclick", "attemptLogin()");
    b1.innerText = "Login"
    b2.setAttribute("onclick", "newUser()");
    b2.innerText = "New User";
}

// checks for user in database
function attemptLogin(){
    var user = document.getElementById("uName").value;
    var pass = document.getElementById("pass").value;

    validate(user, pass);
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
            if(this.responseText == "True"){ 
                alert("User created successfully.");
                login();
            }
            else if(this.responseText == "1"){
                newUser();
                document.getElementById("errors").innerHTML = "Username already taken, choose another.";
            }
        }
    }
    xhttp.open("POST", "../php/createUser.php?username="+encodeURIComponent(user)+"&password="+encodeURIComponent(pass)+"&firstName="+encodeURIComponent(fName)+"&lastName="+encodeURIComponent(lName)+"&email="+encodeURIComponent(email), true);
    xhttp.send();
}

function validate(user, password){    

    // Use AJAX to send source code to server as a string
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){

            if(this.responseText == "True"){
                // alert(this.responseText);
                location.href = 'menu.php';
            }
            else {
                document.getElementById("errors").innerHTML = "Incorrect Username or Password. Please try again.";
                // alert("Incorrect Username or Password. Please try again.");
                // alert(this.responseText);
            }
        }
    }
    xhttp.open("POST", "../php/validate.php?username="+encodeURIComponent(user)+"&password="+encodeURIComponent(password), true);
    xhttp.send();
}

function clearFields(){
    document.getElementById("errors").innerHTML = "";
    while(form.firstChild){
        form.removeChild(form.firstChild);
    }   
}