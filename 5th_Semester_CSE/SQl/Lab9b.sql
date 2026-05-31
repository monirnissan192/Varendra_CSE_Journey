create database P1;
use P1;

create  table tblEmpInfo(
Id int,
Names varchar(25),
Gender varchar(25),
Department_Id int
);
insert into tblEmpInfo (Id,Names,Gender,Department_Id)values
(1,'Jhon','Male',3),
(2,'Moickey','Male',2),
(3,'Roanld','Male',1),
(4,'Sara','female',4),
(5,'Michal','Male',1),
(6,'Smith','Male',3);

select * from tblEmpInfo;

create  table tblDeptInfo(
Dept_Id int,
DepartmentNames varchar(25)
);

insert into tblDeptInfo(Dept_Id ,DepartmentNames) values
(1,'IT'),
(2,'Payroll'),
(3,'HR'),
(4,'Admin');

select * from tblDeptInfo;

alter view dbo.InfoaboutEmployee
with schemabinding
as select Names,DepartmentNames
from dbo. tblEmpInfo inner join dbo.tblDeptInfo
on dbo.tblEmpInfo.Department_Id= dbo.tblDeptInfo.Dept_Id;

select * from dbo.InfoaboutEmployee;

create view InfoaboutEmployee2
with schemabinding
as select Names,DepartmentNames
from dbo. tblEmpInfo inner join dbo.tblDeptInfo
on dbo.tblEmpInfo.Department_Id= dbo.tblDeptInfo.Dept_Id;

select * from dbo.InfoaboutEmployee2;