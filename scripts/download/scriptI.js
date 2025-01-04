function baixarPTBR() {
    const linkA = document.createElement('a');

    linkA.href = "app/Dalavino.exe";
    linkA.download = "Dalavino.exe";

    linkA.click()
}
function baixarEN() {
    const linkB = document.createElement('a');

    linkB.href = "library/apps/vsEN/DalavinoEN.exe";
    linkB.download = "DalavinoEN.exe";

    linkB.click()
}
function baixarES() {
    const linkC = document.createElement('a');

    linkC.href = "library/apps/vsES/DalavinoES.exe";
    linkC.download = "DalavinoES.exe";

    linkC.click()
}
function baixarCPP() {
    const linkC = document.createElement('a');

    linkC.href = "library/apps/vsCPP/DalavinoCpp.cpp";
    linkC.download = "DalavinoCpp.cpp";

    linkC.click()
}