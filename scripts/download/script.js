function baixar() {
    const link = document.createElement('a');

    link.href = "app/Dalavino.exe";
    link.download = "Dalavino.exe";

    link.click()
}

function printA() {
    const linkA = document.createElement('a');

    linkA.href = "design/images/print.png";
    linkA.target = "_blank";

    linkA.click()
}

function library() {
    const linkL = document.createElement('a');
    
    linkL.href = "library.html";
    linkL.target = "_blank";
    
    linkL.click()
}