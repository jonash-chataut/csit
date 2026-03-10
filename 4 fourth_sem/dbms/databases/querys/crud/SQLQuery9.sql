-- Transfer 200.00 from Account 1 to Account 2
EXEC TransferAmount @fromAccount = 1, @toAccount = 2, @transferAmount = 200.00;

-- Check the updated balances
SELECT * FROM Accounts;
