--SQL Source Code:
-- Dropping tables if they exist
DROP TABLE IF EXISTS Student_Details;
DROP TABLE IF EXISTS Subject_Details;
DROP TABLE IF EXISTS Marksheet_details;
GO

-- Creating StudentDetails table
CREATE TABLE StudentDetails (
    RollNo INT NOT NULL,
    StudentName VARCHAR(100),
    PRIMARY KEY (RollNo)
);

-- Creating SubjectDetails table
CREATE TABLE SubjectDetails (
    SubjectId INT NOT NULL,
    SubjectName VARCHAR(100),
    PRIMARY KEY (SubjectId)
);

-- Creating MarksheetDetails table
CREATE TABLE MarksheetDetails (
    RollNo INT NOT NULL,
    SubjectId INT NOT NULL,
    Marks FLOAT,
    FOREIGN KEY (RollNo) REFERENCES StudentDetails(RollNo),
    FOREIGN KEY (SubjectId) REFERENCES SubjectDetails(SubjectId)
);
--Inserting Data into Tables:
-- Inserting students
INSERT INTO StudentDetails (RollNo, StudentName) VALUES
(1, 'Jonash'),
(2, 'Khemant'),
(3, 'Robin');

-- Inserting subjects
INSERT INTO SubjectDetails (SubjectId, SubjectName) VALUES
(8001, 'MATHS'),
(8002, 'C++'),
(8003, 'DSA');

-- Inserting marks
INSERT INTO MarksheetDetails (RollNo, SubjectId, Marks) VALUES
(1, 8001, 98), (1, 8002, 78), (1, 8003, 92), (2, 8001, 92), (2, 8002, 98), (2, 8003, 88), (3, 8001, 90), (3, 8002, 88), (3, 8003, 96);
