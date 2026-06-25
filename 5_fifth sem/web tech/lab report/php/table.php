<?php

    /* Database Connection Parameters */

    $servername = "localhost";

    $username = "root";

    $password = "";




    /* Create Connection */

    $conn = mysqli_connect(
                $servername,
                $username,
                $password,
                "collegeDB"
            );



    /* Check Connection */

    if(!$conn)
    {
        die("Connection Failed: "
            . mysqli_connect_error());
    }

    echo "Connected Successfully<br>";



    /* SQL Query to Create Database */

    // $sql = "CREATE DATABASE collegeDB";



    /* Execute Query */

    // if(mysqli_query($conn, $sql))
    // {
    //     echo "Database Created Successfully";
    // }
    // else
    // {
    //     echo "Error Creating Database: "
    //          . mysqli_error($conn);
    // }

    // SQL query to create table
$sql = "CREATE TABLE IF NOT EXISTS student (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    phone VARCHAR(20)
)";

if (mysqli_query($conn, $sql)) {
    echo "Table 'student' created successfully!";
} else {
    echo "Error creating table: " . mysqli_error($conn);
}


    /* Close Connection */

    mysqli_close($conn);

?>