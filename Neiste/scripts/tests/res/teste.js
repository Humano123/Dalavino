let local = window.location.href;
let t = document.getElementById("title");

if (local.includes("http://127.0.0.1:5500/") && det() === true) {
    t.innerHTML = `Mobile | Teste`;
} else if (local.includes("http://127.0.0.1:5500/") && det() === false) {
    t.innerHTML = `Computador | Teste`;
} else {
    t.innerHTML = "Dalavino";
}