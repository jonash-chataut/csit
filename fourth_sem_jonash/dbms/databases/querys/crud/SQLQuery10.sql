-- Create tables
CREATE TABLE Students (
    std_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    streamm VARCHAR(50)
);

CREATE TABLE Courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50)
);

CREATE TABLE StudentCourses (
    std_id INT,
    course_id INT,
    semester INT,
    PRIMARY KEY (std_id, course_id, semester),
    FOREIGN KEY (std_id) REFERENCES Students(std_id),
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);

CREATE TABLE StudentSemester (
    std_id INT,
    semester INT,
    PRIMARY KEY (std_id, semester),
    FOREIGN KEY (std_id) REFERENCES Students(std_id)
);

-- Insert sample data
INSERT INTO Students (std_id, student_name, streamm)
VALUES
(1, 'Binod', 'BCA'),
(2, 'Jonash', 'CSIT'),
(3, 'Ankit', 'BCA'),
(4, 'Ramesh', 'BIT');

INSERT INTO Courses (course_id, course_name)
VALUES
(1, 'DBMS'),
(2, 'AI'),
(3, 'OS'),
(4, 'TOC'),
(5, 'Image Processing'),
(6, 'OOP');

INSERT INTO StudentSemester (std_id, semester)
VALUES
(1, 7),
(2, 4),
(3, 2),
(4, 6);

-- Verify data
SELECT * FROM Students;
SELECT * FROM Courses;
SELECT * FROM StudentSemester;

-- Cartesian Product: All possible student-course combinations
SELECT 
    s.student_name,
    s.streamm,
    c.course_name
FROM Students s, Courses c
ORDER BY s.std_id, c.course_id;


-- Insert filtered enrollments based on stream
INSERT INTO StudentCourses (std_id, course_id, semester)
SELECT s.std_id, c.course_id, ss.semester

FROM Students s
JOIN StudentSemester ss ON s.std_id = ss.std_id
JOIN Courses c ON (
    (s.streamm = 'CSIT' AND c.course_name IN ('OOP', 'Image Processing', 'TOC')) OR
    (s.streamm = 'BCA' AND c.course_name IN ('OS', 'DBMS', 'AI'))
);

-- Verify enrollments
SELECT * FROM StudentCourses ORDER BY std_id, course_id;


-- Create view
CREATE VIEW StudentCourseDetails AS
SELECT 
    s.std_id,
    s.student_name,
    sc.semester,
    s.streamm,
    c.course_name
FROM 
    Students s
JOIN 
    StudentCourses sc ON s.std_id = sc.std_id
JOIN 
    Courses c ON sc.course_id = c.course_id;
GO

-- Query the view
SELECT * FROM StudentCourseDetails ORDER BY std_id, course_name;
