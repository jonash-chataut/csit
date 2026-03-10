-- 1 Drop existing tables if they exist
DROP TABLE IF EXISTS emaildetails;
DROP TABLE IF EXISTS loandetails;
DROP TABLE IF EXISTS loantype;
DROP TABLE IF EXISTS customerdetails;

-- 2️ Create customerdetails table
CREATE TABLE customerdetails (
    cid INT NOT NULL PRIMARY KEY,
    customername VARCHAR(100),
    email VARCHAR(100),
    phoneno BIGINT,
    address VARCHAR(100)
);

-- 3️ Create loantype table
CREATE TABLE loantype (
    sno INT NOT NULL PRIMARY KEY,
    loantype CHAR(50) UNIQUE -- unique so it can be referenced
);

-- 4️ Create loandetails table with EMI tracking
CREATE TABLE loandetails (
    sno INT NOT NULL PRIMARY KEY,
    cid INT, -- link to customer
    loanname VARCHAR(100),
    loantype CHAR(50),
    interest INT,
    due_date DATE,
    paid_date DATE NULL, -- NULL if unpaid
    FOREIGN KEY (loantype) REFERENCES loantype(loantype),
    FOREIGN KEY (cid) REFERENCES customerdetails(cid)
);

-- 5️ Create emaildetails table
CREATE TABLE emaildetails (
    sno INT NOT NULL,
    [From] VARCHAR(100),
    [To] VARCHAR(100),
    cc VARCHAR(100),
    bcc VARCHAR(100),
    emailbody VARCHAR(100),
    status VARCHAR(100)
);
