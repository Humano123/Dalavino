function det() {
    return /Mobi|Android|iPhone|iPad|iPod|BlackBerry|Windows Phone/.test(navigator.userAgent);
  }
  

  // TRUE = MOBILE
  // FALSE = NÃO MOBILE

  if (det() == true) {
    document.getElementById('baixar').style.display = 'none';
    // document.getElementById('baixarA').style.display = 'none';
    // document.getElementById('subs').style.display = 'block';
    
} else {
    document.getElementById('baixar').style.display = 'block';
    // document.getElementById('baixarA').style.display = 'block';
    // document.getElementById('subs').style.display = 'none';
}