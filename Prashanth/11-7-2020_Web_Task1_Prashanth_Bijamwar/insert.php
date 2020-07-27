<?php
include('db.php');
if(isset($_POST['insrt-btn'])){
    $id=$_POST['id'];
    $nam=$_POST['nam'];
    $bnch = $_POST['bnch'];
    $cgp=$_POST['cgp'];

    $query = "INSERT INTO `students`(`stud_id`,`stud_name`,`branch`,`cgpa`)VALUES('$id','$nam','$bnch','$cgp') ";
    $run=mysqli_query($con,$query);
    if($run)
    {
        echo "Inserted";
    }
    
    else{
        echo "not inserted";
        echo mysqli_error($con);
    }
    

}

?>
