DROP PROCEDURE IF EXISTS sp_SubjectDetails;
GO
CREATE PROCEDURE sp_SubjectDetails
(
	@flag Char,
	@SubjectId Int = NULL,
	@SubjectName Varchar(100) = NULL
)
AS
BEGIN
	If @flag = 's' -- SELECT Data From Table
	BEGIN 
		IF @SubjectId IS NULL
		BEGIN
			Select '0' As STATUS_CODE, 
				'Data Retrived From Table' AS STATUS_MSG

			Select SubjectId,SubjectName
			From SubjectDetails
			RETURN
		END

		Select SubjectId,SubjectName
		From SubjectDetails 
		WHERE SubjectId = @SubjectId
	END


	If @flag = 'i' -- INSERT DATA INTO TABLE
	BEGIN
		IF @SubjectId IS NULL
		BEGIN
			Select '100' As STATUS_CODE, 
			'Subject ID is Missing' AS STATUS_MSG
			RETURN
		END

		IF @SubjectName IS NULL OR @SubjectName = ''
		BEGIN
			Select '101' As STATUS_CODE, 
			'Subject Name is Missing' AS STATUS_MSG
			RETURN
		END

		BEGIN TRY
			Insert Into SubjectDetails(SubjectId, SubjectName)
			Values(@SubjectId, @SubjectName)

			Select '0' AS STATUS_CODE,
			'New Subject is Added successfully' AS STATUS_MSG

		END TRY

		BEGIN CATCH
			Select ERROR_NUMBER() AS STATUS_CODE,
			ERROR_MESSAGE() AS STATUS_MSG
		END CATCH
	END
END
