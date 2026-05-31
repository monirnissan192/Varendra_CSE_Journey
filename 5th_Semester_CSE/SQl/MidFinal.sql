create database MidF;
use Midf;
create table Customer_Table(
Customer_Id int,
Name varchar(50),
Email varchar(50)
);
insert into Customer_Table(Customer_Id,Name ,Email)values
(1,'John Doe','john@example.com'),
(2,'Alice Smith','alice@example.com'),
(3,'Bob White','bob@example.com');

drop table Customer_Table;

create table Orders_Table (
Order_Id int,
 Customer_Id int,
 Product_Id int,
Order_Date date
);

insert into Orders_Table(Order_Id,Customer_Id,Product_Id,Order_Date)values
(1001,1,101,'2025-01-15'),
(1002,1,103,'2025-02-01'),
(1003,2,102,'2025-02-10'),
(1004,2,104,'2025-02-11'),
(1005,3,103,'2025-02-20');

create table Product_Table(
Product_Id int,
Product_Name varchar(50),
Price float

);

insert into Product_Table(Product_Id,Product_Name,Price) values

(101,'Laptop',800.00),
(102,'Smartphone',500.00),
(103,'Headphones',50.00),
(104,'Keyboard',30.00);

--1
select Customer_Id
from Orders_Table
where inner join
on Customer_Table .Customer_Id= Orders_Table.Customer_Id;
--2
select Product_Name
from  Product_Table
where Name='John';
--3 
select Product_Id
from Product_Table
where Product_Id not in
(select Product_Id from Orders_Table);

--4
select sum(Price)
from Product_Table;

