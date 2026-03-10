-- Drop existing table if it exists
DROP TABLE IF EXISTS SubjectDetails;

-- Create SubjectDetails table
CREATE TABLE SubjectDetails (
    SubjectId INT NOT NULL PRIMARY KEY,
    SubjectName VARCHAR(100)
);

-- Insert sample data
INSERT INTO SubjectDetails (SubjectId, SubjectName) VALUES
(235, 'DBMS'),
(236, 'AI'),
(237, 'TOC');

-- Verify the data
SELECT * FROM SubjectDetails;
