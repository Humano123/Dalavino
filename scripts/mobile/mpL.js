function det() {
    return /Mobi|Android|iPhone|iPad|iPod|BlackBerry|Windows Phone/.test(navigator.userAgent);
  }
  

  // TRUE = MOBILE
  // FALSE = NÃO MOBILE

  if (det() == true) {
    document.getElementById('baixarI').style.display = 'none';
    document.getElementById('linguasM').style.display = 'none';
    // document.getElementById('baixarA').style.display = 'none';
    // document.getElementById('subs').style.display = 'block';
    
}