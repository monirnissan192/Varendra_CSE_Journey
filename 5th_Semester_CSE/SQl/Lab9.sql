create database Lab9;
use Lab9;
create table Student(
ID int,
Name varchar(25),
 CGPA float,
Session varchar(25)
);
insert into Student (ID,Name,CGPA,Session)values
(1,'Jackson',3.56,'fall-17'),
(2,'Ronald',3.84,'spring-16'),
(3,'Jemmy',3.96,'fall-17'),
(4,'Sara',2.88,'fall-17');

select * from Student;

--Create View for Only one table Data

/*create view Student_Info
as select ID,Name
from Student;
select * from Student_Info;
*/
--we change the value of view mainly we can add new colomn then we use alter 

alter view Student_Info
as select ID,Name,CGPA
from Student;
select * from Student_Info;

--I can Perform Update Operation for Add new in my View
update Student_info
set CGPA=3.92
where Name='Ronald';
select * from Student_Info;

create  table tblEmployee(
Id int,
Names varchar(25),
Gender varchar(25),
Department_Id int
);
insert into tblEmployee (Id,Names,Gender,Department_Id)values
(1,'Jhon','Male',3),
(2,'Moickey','Male',2),
(3,'Roanld','Male',1),
(4,'Sara','female',4),
(5,'Michal','Male',1),
(6,'Smith','Male',3);

create  table tblDepartment(
Dept_Id int,
DepartmentNames varchar(25)
);

insert into tblDepartment(Dept_Id ,DepartmentNames) values
(1,'IT'),
(2,'Payroll'),
(3,'HR'),
(4,'Admin');


 create view Student_Details
 as select Id,Names,Dept_Id,DepartmentNames
 from tblEmployee
 join tblDepartment
 on tblEmployee.Department_Id=tblDepartment.Dept_Id;

 select * from Student_Details;

 
 update Student_Details
 set DepartmentNames='IT'
 where Names='Jhon'

 select * from Student_Details;