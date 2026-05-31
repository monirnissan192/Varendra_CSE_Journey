create database Lab5;
use Lab5;

create table SectionA(
Id int,
Name varchar(25),
Email varchar(25)
);
insert into SectionA(Id,Name,Email)values
(1,'Tania','Tania@gmail.com'),
(2,'Akib','Akib@gmail.com');
--(3,'Faisal','Faisal@gmail.com');

select * from SectionA;

create table SectionB(
Id int,
Name varchar(25),
Email varchar(25)

);

insert into SectionB(Id,Name,Email)values
(1,'Joynob','Joyno@gmail.com'),
--(2,'Akib'),
(3,'Hasan','Hasn@gmail.com');

select * from SectionB;

drop table SectionA;
drop table SectionB;

--Now the time of Working Set Operation
(select * from SectionA)
union all
(select * from SectionB)

--union al operation repeat Duplicate and not sort in Assending order

 (select * from SectionA)
union 
(select * from SectionB)
--union is vice-varse of union All & don't see duplicate and sort in Aseending order
--I want use order by clause in this unioun Segt operation
 (select * from SectionA)
union 
(select * from SectionB)
Order by Name

--Set operation perform problem

select Id,Name,Email from SectionA
union
Select Name,Id,Email from SectionB
--We See error in this querry

select Id,Name,Email from SectionA
union
Select Id,Email,Name from SectionB

select ASCII('S');
select CHAR(95);
select LTRIM(' Student');
select RTRIM('Student ');
select Lower('STUDENT');
select Upper('student');
select Reverse('Varendra');
select Replicate('Varendra',5);
select Substring('Eaxmple@gmial.com',1,8);
select Replace('Eaxmple@gmail.com','gmail','Yahoo');
select CHARINDEX('@','Example@gmail.com');




