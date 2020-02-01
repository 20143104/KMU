$('#target').prev().attr('style', 'color :red');
$('#target').prevAll().attr('style','color: red');
$('#target').prevUntil('.stop').attr('style', 'color:red');
$('#target').next().attr('style', ' color:green');
$('#target').nextAll().attr('style', 'color:green');
$('#target').nextUntil('.stop').attr('style', 'color:green');


/*
index
var container = $('#container')
container.children().index(target)    3
container.children().get(6)     <div style=​"color:​blue" class=​"stop">​Seventh​</div>​
*/
