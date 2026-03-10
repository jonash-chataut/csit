-- Dropping table if it exists

DROP TABLE IF EXISTS Student_Details;
DROP TABLE IF EXISTS Subject_Details;
DROP TABLE IF EXISTS Marksheet_details;
GO

--CreatingStudentDetailstable

CREATE TABLE Student_Details

(

    Rollno INT NOT NULL,

    Student_name VARCHAR(100),

    PRIMARY KEY (RollNo)

);

-- Creating SubjectDetails table

CREATE TABLE Subject_Details

(

    Subject_Id INT NOT NULL,

    Subject_Name VARCHAR(100),

    PRIMARY KEY (Subject_Id)

);

-- Creating MarksheetDetails table

CREATE TABLE Marksheet_details

(

    Rollno INT NOT NULL,

    Subject_Id INT NOT NULL,

    Marks INT,

FOREIGN KEY (Rollno) REFERENCES Student_Details(Rollno),
FOREIGN KEY (Subject_Id) REFERENCES Subject_Details(Subject_Id)

);
