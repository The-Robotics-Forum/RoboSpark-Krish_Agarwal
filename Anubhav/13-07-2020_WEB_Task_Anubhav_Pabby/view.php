<?php
include('db.php');
if(isset($_POST['submit']))
{
    $studentid=$_POST['studentid'];
   
    $query="SELECT * FROM `students` WHERE `stud_id`='$studentid'";
    $run = mysqli_query($con,$query);

    $row=mysqli_num_rows($run);
    if($row==1){
        echo "<h3>Record found</h3>" . "<br>";
        $user_row=mysqli_fetch_assoc($run);
        echo  "Student ID: " .  $user_row['stud_id'] . "<br>";
        echo  "Student Name: " .  $user_row['stud_name'] . "<br>";
        echo  "Branch: " .  $user_row['branch'] . "<br>";
        echo  "CGPA: " .  $user_row['cgpa'] . "<br>";
    }
    else{
        echo "<h3>No record found</h3>";
    }

    
}
?>
<html>
    <head> 
        <title>Records</title>
        <style>
            body{
                margin:0;
                padding:0;
                background:url("images.png") fixed no-repeat;
                background-size:cover;
            }
        </style>        
    </head>
<body>
    
</body>
</html>