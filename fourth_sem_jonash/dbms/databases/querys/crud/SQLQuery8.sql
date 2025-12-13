-- Create a new database
CREATE DATABASE txns;
GO

-- Use the database
USE txns;
GO

-- Create the Accounts table
CREATE TABLE Accounts (
    AccountID INT PRIMARY KEY,
    Balance DECIMAL(10, 2) NOT NULL
);

-- Insert sample data
INSERT INTO Accounts (AccountID, Balance) 
VALUES (1001, 7500.00), (1002, 4300.00);

-- Verify the data
SELECT * FROM Accounts;

CREATE PROCEDURE TransferAmount
    @fromAccount INT,
    @toAccount INT,
    @transferAmount DECIMAL(10, 2)
AS
BEGIN
    DECLARE @balanceA DECIMAL(10, 2);
    
    -- Start the transaction
    BEGIN TRANSACTION;
    
    BEGIN TRY
        -- Check the balance of the source account
        SELECT @balanceA = Balance
        FROM Accounts
        WHERE AccountID = @fromAccount;
        
        -- Perform the transaction if balance is sufficient
        IF @balanceA >= @transferAmount
        BEGIN
            -- Debit from source account
            UPDATE Accounts
            SET Balance = Balance - @transferAmount
            WHERE AccountID = @fromAccount;
            
            -- Credit to target account
            UPDATE Accounts
            SET Balance = Balance + @transferAmount
            WHERE AccountID = @toAccount;
            
            -- Commit the transaction
            COMMIT TRANSACTION;
            SELECT 'Transaction completed successfully.' AS Message;
        END
        ELSE
        BEGIN
            -- Rollback the transaction if insufficient balance
            ROLLBACK TRANSACTION;
            SELECT 'Transaction failed: Insufficient balance in the source account.' AS Message;
        END
    END TRY
    BEGIN CATCH
        -- Rollback in case of any error
        IF @@TRANCOUNT > 0
            ROLLBACK TRANSACTION;
        SELECT ERROR_MESSAGE() AS Message;
    END CATCH
END;
GO

-- Transfer 200.00 from Account 1 to Account 2
EXEC TransferAmount @fromAccount = 1001, @toAccount = 1002, @transferAmount = 1000.00;

-- Check the updated balances
SELECT * FROM Accounts;

-- Attempt to transfer 75000.00 from Account 1001 (which only has 6500.00)
EXEC TransferAmount @fromAccount = 1001, @toAccount = 1002, @transferAmount = 7500.00;

-- Check the balances (should remain unchanged)
SELECT * FROM Accounts;


-- Transfer exactly 6500.00 from Account 1 (empties the account)
EXEC TransferAmount @fromAccount = 1001, @toAccount = 1002, @transferAmount = 6500.00;

-- Check the updated balances
SELECT * FROM Accounts;

