CREATE PROCEDURE xyzNotification
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @today DATE = GETDATE();

    INSERT INTO emaildetails (sno, [From], [To], cc, bcc, emailbody, status)
    SELECT
        ISNULL((SELECT MAX(sno) FROM emaildetails), 0) 
        + ROW_NUMBER() OVER (ORDER BY c.cid) AS sno,
        'bank_notification@gmail.com' AS [From],
        c.email AS [To],
        NULL AS cc,
        NULL AS bcc,
        CONCAT('Dear ', c.customername, ', your EMI for loan "', l.loanname, '" is overdue. Please pay immediately.') AS emailbody,
        'Pending' AS status
    FROM loandetails l
    JOIN customerdetails c ON l.cid = c.cid
    WHERE l.paid_date IS NULL
      AND l.due_date < @today;
END;
GO
