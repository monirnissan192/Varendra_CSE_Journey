create database demoDB0;
use demoDB0;
create table Student( S_ID int,Names varchar(50));
insert into Student (S_ID,Names) values

(232311192,'Monir Nissan'),
(232311193,'Al Shahriar'),
(232311195,'Rakhiyul Hasan'),
(232311196,'Oheddduzaman ornob');

select * from Student;

--delete from Student
--where Names='Jissan';
--drop table Student;
truncate table Student;