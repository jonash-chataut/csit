sp_help
EXEC sp_SubjectDetails @flag='s', @SubjectId = NULL, @SubjectName = NULL;

EXEC sp_SubjectDetails @flag='s', @SubjectId = 235, @SubjectName = NULL;

EXEC sp_SubjectDetails @flag='i', 
    @SubjectId = 238,
    @SubjectName = 'CN';

-- Verify the insertion
SELECT * FROM SubjectDetails;

EXEC sp_SubjectDetails @flag='i', 
    @SubjectId = NULL,
    @SubjectName = 'OS';

    sp_help

exec sp_help SubjectDetails
