<?php

$conn =  mysqli_connect('localhost','root','','robospark');




if (isset($_POST['submit'])) {
    $ID=$_POST['ID'];
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
      }  
  
  $sql = "SELECT * FROM students WHERE stud_id='$ID'";
  $result = mysqli_query($conn,$sql);
  $row=mysqli_fetch_assoc($result);
  if ($result) {
    // output data of each row
    
      echo "id: " . $row["stud_id"]. "<br>Name: " . $row["stud_name"]. "<br>Branch- " . $row["branch"]. "<br>CGPA -  ". $row["cgpa"];
    
  } else {
    echo "0 results";
  }
  

}

$conn->close();

?>