  $(document).ready(function () {

//*******************************   Control de Salidas Digitales  *************************************
  	var btnState = [0, 0, 0, 0, 0];
  	//var mensaje = [];
  	//var btn = 0;
  	//var led = 0;

  	$('#btn-out-1, #btn-out-2, #btn-out-3, #btn-out-4, #btn-out-5').click(function(){

  		if( this.id == "btn-out-1" ){

  			$('.led-1').toggleClass("led-green");
  			btnState[0] = 1 - btnState[0];
  			console.log( setMessage(btnState[0],0));
  			sendData( setMessage( btnState[0], 0) );

  		}else if( this.id == "btn-out-2" ){

  			$('.led-2').toggleClass("led-green");
  			btnState[1] = 1 - btnState[1];
			console.log( setMessage(btnState[1],1));
  		}else if ( this.id == "btn-out-3" ){

  			$('.led-3').toggleClass("led-green");
  			btnState[2] = 1 - btnState[2];
  			console.log( setMessage( btnState[2], 2));
  		}else if ( this.id == "btn-out-4" ){

  			$('.led-4').toggleClass("led-green");
  			btnState[3] = 1 - btnState[3];
  			console.log( setMessage( btnState[3], 3));
  		}else if ( this.id == "btn-out-5" ){

  			$('.led-5').toggleClass("led-green");
  			btnState[4] = 1 - btnState[4];
  			console.log( setMessage( btnState[4], 4));
  		}

  	});
/*
	  $('#btn-out-1, #btn-out-2, #btn-out-3, #btn-out-4, #btn-out-5').click( function() {

	  		btn = 0;
	  		led = 0;

	  		for (var i = 0; i < btnState.length; i++) {
	  			
	  			btn = "btn-out-"+(i+1);	
	  			led = ".led-"+(i+1);
	  			mensaje[i] = 0;

	  			if(this.id == btn ){
	  				$(led).toggleClass("led-green");
	  				btnState[i] = 1 - btnState[i];
	  				console.log(btn);
	  			}
	  		};

	  		for (var i = 0; i < btnState.length; i++) {
	  			 
	  			 if( btnState[i] == 1 ){
	  			 	mensaje[i] = "Salida"+ (i+1) +"-ON";
	  			 }else{
	  			 	mensaje[i] = "Salida"+ (i+1) +"-OFF";
	  			 }
	  		};
            
	  		for (var i = 0; i < mensaje.length; i++) {
	  				sendData( mensaje[i] );
	  		};
      }); */

function setMessage(btnState, index){
	var message = 0;
	if(btnState == 1){
		message = "Salida"+(index+1)+"-ON";
	}else{
		message = "Salida"+(index+1)+"-OFF";
	}
	return message;
}

/*
      $('#btn-servoc','#btn-servor','#btn-servol').click( function() {
      		if( this.id == "#btn-servoc"){
      			sendData("Servo-Center");
      		}else if( this.id == "#btn-servor"){
      			sendData("Servo-Right");
      		}else if (this.id == "#btn-servol"){
      			sendData("Servo-Left");
      		}
      });
	 */

// ********************      Funciones Socket.io     ******************************	 

  var socket = io();		// socket.io instance

   // this function sends data to the server. It's called when
   // the submit button is pressed:
	function sendData(data) {
		// send the server whatever is in the textInput box:
		socket.emit('message', data);
	}

	// if the server sends you data, act on it:
	socket.on('message', function(data) {
		serverOutput.html(data);
	});

  });