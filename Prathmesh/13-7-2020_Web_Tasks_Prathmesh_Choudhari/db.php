<?php
$conn=new mysqli('localhost','root','','robospark');
//to check if database is connected
if(!$conn){
    echo "Connection error".mysqli_connect_error();
}
else {
    echo "<h3>Database connection success</h3>";
}

?>