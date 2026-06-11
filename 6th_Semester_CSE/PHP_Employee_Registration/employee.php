<?php
$servername= "localhost";
$username="root";
$password="";
$dbname="company";

$conn=new mysqli($servername,$username,$password,$dbname);

if ($conn->connect_error){
    die("Connection failed: " . $conn->connect_error);
}

if($_SERVER["REQUEST_METHOD"] == "POST"){

    $employee_id    = $_POST['Employee_ID'];
    $employee_name  = $_POST['Employee_Name'];
    $email          = $_POST['Email'];
    $phone_number   = $_POST['Phone_Number'];
    $designation    = $_POST['Designation'];
    $gender         = isset($_POST['Gender']) ? $_POST['Gender']:"";

    /*

     -> -> If i write this there is an chance SQL injection attack this is dangerouus.Dangerous because 
     a malicious user could type SQL commands into your HTML form instead of their name. For example, if someone typed '; 
     DROP TABLE employee; -- into the Employee Name field, your database would execute that command and delete your entire table.


    $sql="INSERT INTO employee(employee_id,employee_name,email,phone_number,designation,gender)
          VALUES('$employee_id','$employee_name','$email','$phone_number','$designation','$gender')";

    if($conn->query($sql) === TRUE){
        echo"<h3> Employee Registration Successfully!</h3>";
        echo"Employee Id :".$employee_id."<br>";
        echo"<strong>".$employee_name."</strong>"."<br>";
        echo"Email :".$email."<br>";
        echo"Phone Number :".$phone_number."<br>";
        echo"Designation :".$designation."<br>";
        echo"Gender :".$gender."<br>";
    }
    
    else{
        echo"Error:"."<br>".$conn->error;
    }
        */


    //We used This Solution:

    // Solution:
    //   1.Prepare: Write the SQL with question marks as  plceholder
    $stmt = $conn->prepare("INSERT INTO employee(employee_id,employee_name,email,phone_number,designation,gender)
    values(?,?,?,?,?,?)");

    //2. Attach the variable to the placeholder safely:
    $stmt->bind_param("ssssss",$employee_id,$employee_name,$email,$phone_number,$designation,$gender);
    // The "ssssss" Means we are binding 6 strings

    // Execute: Run the secure query
    if ($stmt->execute()) {
        echo "<h3>Employee Registration Successful!</h3>";
        echo "Employee Id: " . $employee_id . "<br>";
        echo "<strong>" . $employee_name . "</strong><br>";
        echo "Email: " . $email . "<br>";
        echo "Phone number: " . $phone_number . "<br>";
        echo "Designation: " . $designation . "<br>";
        echo "Gender: " . $gender . "<br>";

    } else {
        echo "Error: <br>" . $stmt->error;
    }
    // Close the statement:
    $stmt->close();
}
$conn->close();
?>