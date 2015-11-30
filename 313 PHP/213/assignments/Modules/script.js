function gotoPage(){
  var list = document.myForm.mySelect;
  location.href = list.options[list.selectedIndex].value;
}

function changeTextBox(){
	var testTake = document.getElementById('testTake').value;
	if (testTake == 'check'){
		var current = document.getElementById('hide').style.display;
		if (current == 'none'){
			document.getElementById('hide').style.display="block";
		}
		else {
			document.getElementById('hide').style.display="none";
		}
	}
}	