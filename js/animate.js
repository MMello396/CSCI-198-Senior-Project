var myVar;

function myFunction(){
    myVar = setTimeout(showPage, 2700);
}

function showPage() {
    document.getElementById("loader").style.display = "none";
    document.getElementById("cover").style.display = "none";
}