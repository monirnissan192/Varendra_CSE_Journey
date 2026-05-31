Create database LabM;
use LabM;

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

drop table Orders_Table;

create table Product_Table(
Product_Id int,
Product_Name varchar(50),
Price Float
);

insert into Product_Table(Product_Id,Product_Name,Price) values

(101,'Laptop',800.00),
(102,'Smartphone',500.00),
(103,'Headphones',50.00),
(104,'Keyboard',30.00);
drop table Product_Table;

--1 
select Customer_Table.Name,Product_Table.Product_Name
from  Customer_Table
inner join Orders_Table 
on Customer_Table.Customer_Id = Orders_Table.Customer_Id
inner join Product_Table 
on Product_Table.Product_Id = Orders_Table.Product_Id;
--2 
select  Product_Table.Product_Name
From Orders_Table
inner join Customer_Table 
    on Orders_Table.Customer_Id = Customer_Table.Customer_Id
inner join Product_Table 
    on Orders_Table.Product_Id = Product_Table.Product_Id
where Customer_Table.Name = 'John Doe';

--3
select Customer_Table.Name,count(Orders_Table.Product_Id) as Total_Products_Ordered
from Customer_Table
inner join Orders_Table 
on Customer_Table.Customer_Id = Orders_Table.Customer_Id
group by Customer_Table.Name;

--For Sir Helping I write this 3 Code Succesfully
--5
select sum(Price)
from Product_Table;
--This is Code is not Correct
