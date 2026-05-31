create database Lab9c;
use  Lab9c;

create table tblEmp(
EmpId varchar(25),
EmpName varchar(25),
EmpSalary int,
EmpJoinDate date
);

insert into tblEmp(EmpId,EmpName,EmpSalary,EmpJoinDate) values
('02345','Rasel',25000,'2018-01-01'),
('02452','Nishan',15000,'2018-05-15'),
('02666','Munira',32000,'2019-01-15'),
('02788','Sadia',45000,'2019-02-20');

select * from tblEmp;

create table Student(
Id varchar(25),
District varchar(25),
Dept varchar(25)
);

insert into  Student(Id,District,Dept) values
('02345','Dhaka','IT'),
('02452','Rajshahi','IT'),
('02666','Rajshahi','HR'),
('02788','Khulna','PO');

select *from Student;

create table Industry(
Industry varchar(25),
--Industry_Code int not null Primary key,
Industry_Code int,
Employees int,
Annual_Income varchar(25)
);

insert into Industry(Industry,Industry_Code,Employees ,Annual_Income) values

('ACI',1234,200,'$150'),
('SK-F',3254,150,'$2563'),
('RFL',1489,117,'$4857'),
('GMG Airlines',2541,253,'$3350');


select Industry
from Industry;

create view EmpDetail
with schemabinding
as
select EmpName, EmpSalary
from dbo.tblEmp
where EmpSalary between 15000 and 20000 
and EmpName like '%a%'


select * from EmpDetail;

create view EmpDetail1
with schemabinding
as 
select EmpName, EmpSalary,Dept
from dbo.tblEmp join dbo.Student
on dbo.tblEmp.EmpId= dbo.Student.Id

select * from EmpDetail1;

--Example of Joining there datatype same but there values are does'not match that's why we don't see an output;
create view EmpDetail2
with schemabinding
as 
select EmpName, EmpSalary,Dept
from dbo.tblEmp join dbo.Student
on dbo.tblEmp.EmpName= dbo.Student.District
select * from EmpDetail2;

--Inner and Join is Same when we write join in querry then sql kno i want inner join

select * from  EmpDetail2;

update EmpDetail1
Set Dept='Accounts'
where EmpName='Rasel';

select * from  EmpDetail1;

create clustered index CI_Industry
on Industry(Industry_Code);

create nonclustered index NCI_Industry
on Industry(Annual_Income);

select * from Industry;
