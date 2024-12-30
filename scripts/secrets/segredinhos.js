function segredoUM() {
    document.getElementById("all").style.perspective = "800px";
    document.getElementById("body").style.transform = "rotateX(180deg)";

    document.getElementById("jackA").innerHTML = "):";
    document.getElementById("jackB").innerHTML = ":(";
}

function segredoDOIS() {
    document.getElementById("all").style.perspective = "800px";
    document.getElementById("body").style.transform = "rotate(0deg)";

    document.getElementById("jackA").innerHTML = "(:";
    document.getElementById("jackB").innerHTML = ":)";
}