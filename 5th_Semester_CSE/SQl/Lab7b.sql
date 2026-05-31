create database Lab7b;

create table emp(
empName varchar(50),
empHead varchar(50)
);
insert into emp(empName,empHead) values
('jon',NULL),
('Smith','David')

--Same Querry
SELECT empName,
ISNULL(empHead, 'Hayes') AS Head
FROM emp
where empName='Jon';
--Same Querry
SELECT empName,
ISNULL(empHead, 'Hayes') AS Head
FROM emp;

SELECT empName,
COALESCE (empHead, 'Hayes') AS Head
FROM emp;

--Write the difference between ISNULL() and COALESCE().
--Answer: COALESCE() can return not-null value first but the ISNULL() can not  differentiate between null and not-null values
--COALSCE Cheak

create table names(
FirstName varchar(20),
MiddleName varchar(20),
LastName varchar(20)
);
insert into names(FirstName,LastName,MiddleName) values
(NULL,'APJ','ABUL'),
('APJ','ABUL',NULL),
('APJ',NULL,'ABUL')

select * from names;


--Just See How Coalesce Work all time chose Not Null value
select coalesce (FirstName,LastName,MiddleName)
from names
--select* from names
--Isnull doesn't know the differentiate between null value and Not null value
SELECT ISNULL(ISNULL(FirstName, LastName), MiddleName)
FROM names

--Cartesian or Cross Join Operation

create table Teacher(
Names varchar(25),
ID int
);

insert into Teacher(Names,ID) values
('Sumaiya Rahman',1),
('Jannatul Ferdous',2)

create table Student(
Names varchar(25),
ID int
);
drop table Student

insert into Student(Names,ID) values
('Jara',1),
('Smith',2),
('Sara',3)



SELECT Teacher.Names AS Teacher_Name, Teacher.ID AS Teacher_ID,
       Student.Names AS Student_Name, Student.ID AS Student_ID
FROM Teacher
CROSS JOIN Student;

