create database Lab8a;
use Lab8a;

create table Emp_Details(
Emp_Id int primary key,
Emp_name varchar(25)
);
insert into Emp_Details(Emp_Id,Emp_Name)values
(1,'Arafat'),
(3,'Akib'),
(2,'Anika'),
(5,'Smith');
select *From Emp_Details;
--drop table Emp_Details;
--When i execute this code then i see my output's are autometic Assending order whene i declare Primary key any key Any colomn 
--this by Deafault create Clustered index

--Now I am gonna create a mannuan clustred index

create table Emp_Details1(
Emp_Id int,
Emp_name varchar(25)
);
insert into Emp_Details1(Emp_Id,Emp_Name)values
(1,'Arafat'),
(3,'Akib'),
(2,'Anika'),
(5,'Smith');
drop table Emp_Details1;
create clustered index CI_demo
on Emp_Details1(Emp_Id)

select * from Emp_Details1;
--That's like Manually Clustered index Created 

--In a table just one Clusterd index created not Multiple..

--If i want to change Clusterd index in another colomn so first work is drop clustered index

drop index CI_demo on Emp_Details1;

create clustered index CI_demo
on Emp_Details1(Emp_Name);

select * from Emp_Details1;

--in this time i change indexing from Emp_Id to Emp_Name so then i can see Emp_name in Assending order

--now create Non clusterd index

create nonclustered index NCI_demo
on Emp_Details1(Emp_Id);

select * from Emp_Details1;

create nonclustered index NCI_demo1
on Emp_Details1(Emp_Name);

select * from Emp_Details1;


drop index NCI_demo on Emp_Details1;
drop index NCI_demo1 on Emp_Details1;

--The output will be in ascending order of the column I am working with it's do Physically Sorted yes and Output Sorted yes Guaranteed yes in Clustered index.

--Physically Sorted No and Output Sorted Maybe Guaranteed Not guaranteed in Non Clustered Index
