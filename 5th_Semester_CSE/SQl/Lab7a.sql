
create database Lab7a;

create table Departments(
Department_ID int,
Department_Name varchar(50),
Locations varchar(200)
);

insert into Departments(Department_ID,Department_Name,Locations) values
(1,'HR','New York'),
(2,'IT','San Francisco'),
(3,'Finance','Chicago'),
(4,'Marketing','Boston');



create table Employees(
Employee_ID int,
FirstName varchar(50),
LastName varchar(50),
Department_ID int,
Salary int,
HireDate date
);

select * from Employees

insert into Employees(Employee_ID,FirstName,LastName,Department_ID,Salary,HireDate) values
(101,'John','Smith',1,60000,'2018-05-10'),
(102,'Sarah','Johnson',2,85000,'2019-03-15'),
(103,'Michael','Brown',2,95000,'2017-07-23'),
(104,'Emily','Davis',3,72000,'2020-01-11'),
(105,'Daniel','Wilson',4,68000,'2021-09-05')
--1

select Employee_ID,Department_ID,Salary
from Employees
where Salary > (select avg(Salary)
from Employees as Sub
where Sub.Department_ID = Employees.Department_ID
);
--2
select Department_ID
from Employees
except
select Department_ID
from Departments;
--3
select Employee_ID,Department_ID,Salary
from Employees
where Salary < (select max(Salary)
from Employees as Nissan
where Nissan.Department_ID=Employees.Department_ID
);
--4
select Employee_ID,FirstName,LastName,Department_ID,HireDate
from Employees
where  Department_ID in  (Select max(Department_ID)
from Employees as Monir
where Monir.Department_ID=Employees.Department_ID
);
--5
select Employee_ID, FirstName, LastName, Department_ID
from Employees
where Department_ID in(select Department_ID
from Employees
group by Department_ID
having count(*) > 1
);
--5
select Department_ID
from Employees
intersect
(select Department_ID
from Employees);
--5
SELECT e1.Employee_ID, e1.FirstName, e1.LastName, e1.Department_ID
FROM Employees e1
JOIN Employees e2
ON e1.Department_ID = e2.Department_ID
AND e1.Employee_ID <> e2.Employee_ID;



