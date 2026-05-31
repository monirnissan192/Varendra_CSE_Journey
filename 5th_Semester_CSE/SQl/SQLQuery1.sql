create database demoDB;
use demoDB;
--Querry for Table
create table Student(
S_ID int,Names Varchar(10),
CGPA float
);

insert into Student Values (232311196,'Jissan',3.31);

--select S_ID,Names from Student;
select * from Student;

--Select S_ID , Names from Student;

--delete from Student
--where CGPA=3.65;

--drop  table Student;
--truncate table Student;