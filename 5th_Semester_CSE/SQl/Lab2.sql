create database Lab2;
use Lab2;

create table Branch(
Branch_Name varchar(25),
Branch_Id int,
Branch_City varchar(25) 
);

select * from Branch;

--Multiple value inserting Sysytem

insert into Branch(Branch_Name,Branch_Id,Branch_City) values
('Kazla',100,'Rajshahi'),

('ZeroPoint',101,'Rajshahi'),

('Ullapara',102,'Sirajganj');

 --Single value inserting System
 
 insert into Branch values('Kazla',100,'Rajshahi');

 insert into Branch values('ZeroPoint',101,'Rajshahi');

 insert into Branch values('Ullapara',102,'Sirajganj');

 insert into Branch values('Kazla',103,'Dhaka',60000);

 --drop table Branch;

 --Adding one extra table using Alter Clause

 alter table Branch add Amount int;

 update Branch
 set Amount=30000
 where Branch_Id=100;

 update Branch
 set Amount=34000
 where Branch_Id=101;

 update Branch
 set Amount=20000
 where Branch_Id=102;

 --using distinct to cut same name.Same name cuting but not in table

 select distinct Branch_Name from Branch;
 select all Branch_Name from Branch;

 --Add condition in Sql

 select Branch_Name from Branch
 where Amount between 30000 and 40000;

