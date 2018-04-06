function loadImages() {
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured1.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured2.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured3.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured4.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured5.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured6.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured7.png')}} width='300' height='300' />");
		$("#ImagePanel1").append("<img id = 'test' src = {{ url_for('static', filename='MotionCaptured8.png')}} width='300' height='300' />");
}
function moveCarViaRest(direction) {
         $.ajax({ 
             type: "POST",
	     contentType:"application/json",
             dataType: "json",
             url: "http://192.168.137.84:5001/Controls?direction=" + direction,
	     crossDomain: true,
             success: function(data){        
                alert(data);
             },
	     error: function (jqXHR, textStatus, errorThrown) {
		console.log(jqXHR.responseText);
             }
         });
}
function mouseDown1() {
   moveCarViaRest('up');
}
function mouseDown2() {
   moveCarViaRest('down');
}
function mouseDown3() {
   moveCarViaRest('left');
}
function mouseDown4() {
   moveCarViaRest('right');
}
function mouseDown5() {
   moveCarViaRest('down');
}
function mouseUp() {
   moveCarViaRest('stop');
}