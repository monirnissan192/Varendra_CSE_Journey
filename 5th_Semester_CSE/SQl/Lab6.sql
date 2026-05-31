create database Encription;
--Encription Code
create table UserInfo(
Id int,
Balanced int,
Pin varchar(25)
);

insert into  UserInfo(Id,Balanced,Pin)values
(10001,50000,HASHBYTES('SHA1','ab1')),
(10002,55000,HASHBYTES('SHA1','ba1'));

select * from  UserInfo;

--Join Operation

create table Loan(
Loan_number varchar(15),
Branch_name varchar(25),
Amount int
);
insert into Loan(Loan_number,Branch_name,Amount) Values
('L-170','Downtown',3000),
('L-230','Redwood',4000),
('L-260','Perryridge',1700);

create table Borrower(
Customer_name varchar(25),
Loan_number varchar(15)
);

insert into Borrower(Customer_name,Loan_number) Values
('Jones','L-170'),
('Hayes','L-155'),
('Smith','L-230')

--Inner Join Operation
select * from Loan
inner join Borrower
on Loan.Loan_number=Borrower.Loan_number;
--Left join/Left Outer Join
select * from Loan
left join Borrower
on Loan.Loan_number=Borrower.Loan_number;
--Right join/Right Outer Join
select * from Loan
right join Borrower
on Loan.Loan_number=Borrower.Loan_number;
--Full Join Operation/Full Outer Join
select * from Loan
full join Borrower
on Loan.Loan_number=Borrower.Loan_number;

select Loan.Loan_number,Borrower.Loan_number
from Loan
inner join Borrower
on Loan.Loan_number=Borrower.Loan_number;
