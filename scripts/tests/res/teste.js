function det() {
    return /Mobi|Android|iPhone|iPad|iPod|BlackBerry|Windows Phone/.test(navigator.userAgent);
  }
  

  let local = window.location.href;
let t = document.getElementById("title");

if (local.includes("http://127.0.0.1:5500/") && det() === true) {
    t.innerHTML = `Mobile | Teste`;
} 
if (local.includes("http://127.0.0.1:5500/") && det() === false) {
    t.innerHTML = `Computador | Teste`;
}