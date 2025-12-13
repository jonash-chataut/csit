-- Insert sample customers
INSERT INTO customerdetails (cid, customername, email, phoneno, address)
VALUES
(1, 'Jonash Chatuat', 'jonashchataut@gmail.com', 9877894562, 'Nepal'),
(2, 'Mohit Singh', 'mohit@gmial.com', 9178956778, 'China'),
(3, 'Binod Kumar', 'binod@gmail.com', 9459988578, 'USA');

-- Insert loan types
INSERT INTO loantype (sno, loantype)
VALUES
(1, 'Home Loan'),
(2, 'Car Loan'),
(3, 'Personal Loan');

-- Insert loans with EMI info
INSERT INTO loandetails (sno, cid, loanname, loantype, interest, due_date, paid_date)
VALUES
(1, 1, 'Hilux loan', 'Car Loan', 8, '2025-05-21', NULL), -- overdue
(2, 2, 'House building', 'Home Loan', 5, '2025-08-15', '2025-08-10'), -- paid
(3, 3, 'Vacation', 'Personal Loan', 12, '2025-08-05', NULL); -- overdue
