<?php
include('db.php');
if(isset($_POST['submit'])){
    $stud_id = $_POST['stud_id'];
    $query = "SELECT * FROM `students` WHERE `stud_id`='$stud_id'";
    $run = mysqli_query($con, $query);
    $row = mysqli_num_rows($run);
    if($row==1)
    {
        $stud_id_details = mysqli_fetch_assoc($run);
    }
    else
    {

    }
}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Student Database</title>
        <link rel="stylesheet" href="student.css">
    </head>
    <body>
        <div class="main">
            <h1>Student Details</h1>
            <h2><?php if($row!=1) echo "Student Id: $stud_id is not present" ?></h2>
            <table style="width:100%">
                <tr>
                    <th>Student Id</th>
                    <th>Student Name</th> 
                    <th>Branch</th>
                    <th>CGPA</th>
                </tr>
                <tr>
                    <td><?php if($row==1) echo $stud_id_details['stud_id']; else echo "-"; ?></td>
                    <td><?php if($row==1) echo $stud_id_details['stud_name']; else echo "-"; ?></td>
                    <td><?php if($row==1) echo $stud_id_details['branch']; else echo "-"; ?></td>
                    <td><?php if($row==1) echo $stud_id_details['cgpa']; else echo "-"; ?></td>
                </tr>
            </table>
        </div>
    </body>
</html>
