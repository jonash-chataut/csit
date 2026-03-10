drop table if exists customer;
drop table if exists borrows;
drop table if exists loan;

create table customer
(
--customerid int not null,
customerid int primary key,
customername varchar(100),
address varchar(100),
phone bigint,
email varchar(100),
--primary key (customerid)
)

create table loan
(
	--loannumber bigint not null,
	loannumber bigint primary key,
	loantype varchar(50),
	amount float,
	--primary key (loannumber)
)

create table borrows
(
	customerid int not null,
	loannumber bigint not null,
	PRIMARY KEY (customerid, loannumber),
	foreign key (customerid) references customer(customerid),
	foreign key (loannumber) references loan(loannumber)
)

insert into customer  (customerid,customername,address,phone,email) values
(100,'Joe','Lalitpur',9875641245,'joe@gmail.com'),
(101,'Henry','Anamnagar',9645641249,'henry@gmail.com'),
(102,'Emma','New baneshor',9848765423,'emma@gmail.com'),
(103,'Rose','Thapagaun',9145697845,'rose@gmail.com'),
(104,'Jona','Lalitpur',9800456978,'jona@gmail.com'),
(105,'Ben','Kalanki',9645897825,'ben@gmail.com'),
(106,'Mona','Lalitpur',9245789615,'mona@gmail.com');

insert into loan (loannumber, loantype, amount) values
  (1001, 'Home Loan', 2500000.00),
  (1002, 'Car Loan', 1500000.00),
  (1003, 'Personal Loan', 75000.00);

insert into borrows (customerid, loannumber) values
  (100, 1001),
  (100, 1002),
  (101, 1002),
  (102, 1003),
  (103, 1001),
  (106, 1003);

--customer from Lalipur
select c.customername
from customer as c
where c.address='Lalitpur'
order by c.customername asc;

--Number of customers with loan
select count(distinct customer.customerid) as num_of_customer_with_loan
from customer 
join borrows on customer.customerid = borrows.customerid;

--customer with loan higher than 50000
select distinct c.customername
from customer c
join borrows b on c.customerid = b.customerid
join loan l on l.loannumber = b.loannumber
where l.amount >= 50000;

--avg loan
select loantype, avg(amount) as average_amount
from loan
group by loantype;
