create database Lab9a;
use Lab9a;

select * from Student;
--In this code we can create  a backend table 
-- Type cating and date Styling Using Cast and Convert function
select *from EMP;

select convert(varchar,cast(Joining_Date as date),102)
 as Joining_Date  from EMP;

 select convert(varchar,cast(Joining_Date as date),9)
 as Joining_Date  from EMP;

 select convert(varchar,cast(Joining_Date as date),104)
 as Joining_Date  from EMP;

 select abs(-5);
 select ceiling(5.5);
 select floor(5.5);
 select power(5,2);
 select Square(10);
 select sqrt(16);

 select getdate();
 select sysdatetime();

 select isdate('VU') as dates;
 select isdate('2020-10-29') as dates;
 select isdate(2025-12-27) as dates;

 select day('2025-10-29');
 select month('2025-10-29');
 select year('2025-10-29');

 select dateadd (day,10,'2025-10-29');
 select dateadd (month,10,'2025-10-29');
 select dateadd (year,10,'2025-10-29');

 select datediff (day,'2020-10-29','2025-10-29');
 select datediff (month,'2020-10-29','2025-10-29');
 select datediff (year,'2020-10-29','2025-10-29');

 --if i subtract [present date - Previous date then we see negative output
 select datediff (year,'2025-10-29','2020-10-29');

 select datename (month,'2025-10-29');
 select datename (day,'2025-10-29');
 select datename (year,'2025-10-29');

 select datename (weekday,'2025-10-29');
