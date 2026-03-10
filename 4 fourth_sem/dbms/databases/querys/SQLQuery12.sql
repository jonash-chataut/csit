--Creating tables
Create table Product_details 
( 
ProductID int NOT NULL, 
ProductName varchar(255), 
Price float, 
Discount float, 
Description varchar(500), 
PRIMARY KEY(ProductID) 
); 
Create table CustomerDetails 
( 
CustomerID int NOT NULL, 
CustomerName varchar(100), 
Email varchar(255), 
Mobile Bigint, 
DOB date, 
Address Varchar(255) 
PRIMARY KEY(CustomerID) 
); 
Create table TxnDetails 
( 
TxnID int NOT NULL, 
TxnDateTime datetime, 
PaymentStatus char, 
PRIMARY KEY(TxnID), 
CustomerID int, 
Foreign Key (CustomerID) References CustomerDetails(CustomerID), 
ProductID int, 
Foreign Key (ProductID) References Product_Details(ProductID), 
); 
