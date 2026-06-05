// print (console.log("Monir Nissan"))
// alert("Don't click");
// document.writeln("Monir Nissan")
// function changecolor(){
//     document.body.style.backgroundColor="lightblue";
// }

// function changecolor(){
//     document.getElementById("abc").style.color="lightblue";
// }

//Add name with welcome See...

// function changecolor(){
//     var yourName=document.getElementById("name").value;
//     document.getElementById("output").innerHTML="Welcome "+yourName;
// }

//Valid email checking...

// function changecolor(){
// var yourName=document.getElementById("email").value
// if(!yourName.includes("@")){
//     alert("Your emali is not valid");
// }
// else{
// alert("Your emali looks good!");    
// }
// }
 function changecolor(){
    let yourName=document.getElementById("name").value
    let yourEmail=document.getElementById("email").value
    let yourPass=document.getElementById("password").value
    if(yourName==="" || yourEmail===""||yourPass===""){
    document.getElementById("error").style.color="red";
    document.getElementById("error").innerHTML="Error Must Fill Everything!"
    }
    else{
        // alert("Success! Welcome to the application, " + yourName)
         document.getElementById("error").style.color="green";
          document.getElementById("error").innerHTML="Success!Welcome "+yourName

    }
 }
