create database P;
use P;
create table Teacher(
Teacher_name varchar(50),
Teacher_Id int,
Teacher_Dept varchar(30),
Teacher_Salary int);
insert into Teacher  (Teacher_name,Teacher_Id,Teacher_Dept,Teacher_Salary) values
('Ahmmed Hossain',2323111,'CSE',50000),
('Monir Hossain',2323112,'BBB',60000),
('Ahmmed Khan',2323113,'CSE',50000),
('Samir Hossain',23231114,'CSE',70000);

create table Student(
Student_name varchar(50),
Student_Id int,
Student_Dept varchar(30),
Student_Fees int);

insert into Student (Student_name,Student_Id,Student_Dept,Student_Fees) values
('Ohedduzaman Ornob',2323111,'CSE',50000),
('Monir Nissan',2323112,'BBB',40000),
('Al Shahriar',2323113,'CSE',50000),
('Jadidda jahan Priyonti',23231114,'BBA',40000),
('Mahir Agraoul',23231115,'CSE',40000),
('Obaidul Qadar',23231116,'BBA',40000),
('Siam Sabbir',23231117,'CSE',40000),
('Cristiano Ronaldo',23231118,'BBA',40000);

select *from Teacher;
select * from Student;
drop table Student;

create table Oper(
Names varchar(30),
 B_Id int
);
insert into Oper(Names,B_Id) values
('Nissan',22),
('Shakil',23),
('Jissan',25);

create table Oper1(
Names varchar(30),
D_Id int
);
insert into Oper1(Names,D_Id) values
('Nissan',44),
('Siam',33),
('Bishal',11);

(select Names 
from Oper)
union
(select Names from Oper1)

(select Names 
from Oper)
intersect
(select Names from Oper1);

(select Names 
from Oper)
Except
(select Names from Oper1)

(select Names 
from Oper)
union all
(select Names from Oper1)


drop table Oper;
drop table Oper1;





