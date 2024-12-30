function det() {
    return /Mobi|Android|iPhone|iPad|iPod|BlackBerry|Windows Phone/.test(navigator.userAgent);
  }
  
  console.log(det());

  // TRUE = MOBILE
  // FALSE = NÃO MOBILE

  if (det() == true) {
    document.getElementById('baixar').style.display = 'none';
    // document.getElementById('baixarA').style.display = 'none';
    // document.getElementById('subs').style.display = 'block';
    console.log("t");
    
} else {
    document.getElementById('baixar').style.display = 'block';
    // document.getElementById('baixarA').style.display = 'block';
    // document.getElementById('subs').style.display = 'none';
    console.log("f");
}