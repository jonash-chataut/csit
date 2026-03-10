--Creating a table
Drop table if exists studentexamdetails
DROP TABLE IF EXISTS students;
CREATE TABLE students (
    studentid INT NOT NULL PRIMARY KEY,
    batchid INT
);

--Inserting data
INSERT INTO students(studentid, batchid) VALUES
(100, 2080),
(101, 2080),
(102, 2080),
(103, 2080),
(104, 2081),
(105, 2082),
(106, 2083);
select * from students

--Creating Stored Procedure
CREATE PROCEDURE ABC
AS
BEGIN 
DROP TABLE IF EXISTS studentexamdetails;
-- Create the new table
CREATE TABLE studentexamdetails (
        Sno INT PRIMARY KEY IDENTITY(1,1),
        studentid INT,
        remarks VARCHAR(50),
        FOREIGN KEY (studentid) REFERENCES students(studentid)
    );

    -- Insert studentid and remarks into studentexamdetails
    INSERT INTO studentexamdetails (studentid, remarks)
    SELECT studentid, 'pass'
    FROM students
    WHERE batchid = '2080';
END;
GO


--Excuting the procedure
exec ABC
select * from studentexamdetails
