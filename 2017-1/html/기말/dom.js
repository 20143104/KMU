function displaydate(){
  document.getElementById("demo").innerHTML= Date();
}
function doubleclick(){
  console.log("ddD");
  document.getElementsByTagName("p").innerHTML = "show me the money";
}
function bigger(x){
  x.style.fontSize="3em";
}
function normal(x){
  x.style.fontSize="1em";
}
function keypress(event){
  document.getElementById("demo").innerHTML = event.keyCode +  " " + String.fromCharCode(event.keyCode);
}



$('#serialize').click(function() {

  person = new Object();

  person.firstName = $('#first-name').val();

  person.lastName = $('#last-name').val();

  var jsonString = JSON.stringify(person);

  $('#raw-json').val(jsonString);

});



$('#deserialize').click(function() {

  var jsonString = $('#raw-json').val();

  person = JSON.parse(jsonString);

  $('#first-name').val(person["firstName"]);

  $('#last-name').val(person.lastName);

});
$('#button-1').click(function() {

  $('#display').text("Button 1 is clicked");

  $('#clicked-ID').text($(this).attr('id'));

});



$('#button-2').click(function() {

//  You can call either trigger('click') or

//  click() method. The effect is the same

//  $('#button-1').trigger('click');

  $('#button-1').click();

  $('#clicked-ID').text($(this).attr('id'));

});
