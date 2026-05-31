create database Lab4;
use Lab4;
create table Worker(
Worker_Id int,First_Name varchar(50),Last_Name varchar(50),salary int,Joining_Date date,Department varchar(50)
);
insert into Worker(Worker_Id,First_Name,Last_Name,salary,Joining_Date,Department) values
(1,'Rana','Hamid',100000,'2025-08-18','HR'),
(2,'Sanjoy','Saha',80000,'2025-08-18','Admin'),
(3,'Mahmudul','Hasan',300000,'2025-08-18','HR'),
(4,'Asad','Zaman',500000,'2025-08-18','Admin'),
(5,'Sajib','Mia',500000,'2025-08-18','Admin'),
(6,'Alamgir','Kabir',200000,'2025-08-18','Account'),
(7,'Foridul','Islam',75000,'2025-08-18','Account'),
(8,'Keshob','Ray',300000,'2025-08-18','Admin');

select* from Worker;

drop table Worker;

select Department,count(*) as Admin_Count
from Worker
group by  Department
having Department='Admin';

select First_name+' '+Last_Name as Names
from Worker
where Salary between 50000 and 100000;

select Department,count(*) as Total_Worker
from Worker
group by  Department
order by Total_Worker desc;

select First_Name,count(*) as New_Count
from Worker
group by  First_Name
order by New_Count asc;

select First_name+' '+Last_Name  Full_Name
from Worker
where Department='HR' or Department='Admin';

drop table Worker;

