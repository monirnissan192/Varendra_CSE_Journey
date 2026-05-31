create database ass1;
use ass1;

create table meve_employe(
employe_name varchar(50),
Street varchar(50),
city varchar(50));

 insert into meve_employe (employe_name,Street,city) values

 ('Arif','51 Upasahar','Rajshahi'),
('Sumon','52 East','Moynamati'),
('Sagor','Neemgachi','Rajshahi'),
('Abdul','Binodpur','Rajshahi'),
('Himesh','Nazru Avaneu','Dhaka'),
('Amirul','ChawkBazar','sylhet'),
('Sajib','99 Worth','Chittagong');

 select * from meve_employe;

 create table meve_works (
 employe_name varchar(50),
 Company_name varchar(50),
 Salary int);

 insert into meve_works(employe_name,Company_name ,Salary) values

 ('Sumon','Agrani',12000),
('Abdul','Sonali',13000),
('Himesh','Agrani',6000),
('Amirul','Sonali',20000),
('Sagor','Sonali',8000),
('Arif','Janata',13000),
('Sajib','Janata',9000);

 select * from meve_works;

 select employe_name 
 from meve_employe
 where city='Rajshahi';

 select employe_name,Street 
 from meve_employe
 where city='Rajshahi';

 select employe_name 
 from meve_works
 where Company_name='Sonali';

  select employe_name 
 from meve_works
 where Company_name='Agrani';

  select employe_name 
 from meve_works
 where Company_name='Janata';

 select employe_name,Salary 
 from meve_works
 where Company_name='Sonali';

  select employe_name,Salary 
 from meve_works
 where Company_name='Agrani';

 select employe_name,Salary
 from meve_works
 where Company_name='Janata';

 select employe_name 
 from meve_works
 where Salary=12000;

  select employe_name 
 from meve_works
 where Salary>=12000;

  select employe_name 
 from meve_works
 where Salary<12000;

 select employe_name,Company_name 
 from meve_works
 where Salary=12000;

 select employe_name,Company_name 
 from meve_works
 where Salary>=12000;

 select employe_name,Company_name 
 from meve_works
 where Salary<12000;

 select employe_name,Street,city
 from meve_employe
 where employe_name in
 (select employe_name
 from meve_works
 where Company_name='Agrani'
 );

 select employe_name,Street,city
 from meve_employe
 where employe_name in
 (select employe_name
 from meve_works
 where Salary>=10000
 );

 select employe_name,Company_name, salary 
from meve_works
where employe_name in(
select employe_name 
from meve_employe
where City = 'Rajshahi');

select employe_name, street, City,
       (select company_name 
        from meve_works 
        where employe_name = meve_employe.employe_name) as company_name
from meve_employe
where employe_name IN (
    select employe_name
    from meve_works
    where salary >= 10000
	);

select employe_name, street, City 
from meve_employee
where employe_name in(
select employe_name 
from meve_works
where company_name = 'Sonali' and salary > 12000);

select employe_name 
from meve_employe
where employe_name  Not in(
select employe_name 
from meve_works
where company_name = 'Sonali');
--here 
select employe_name 
from  meve_works
where employe_name  Not in(
select employe_name 
from meve_employe
where company_name = 'Sonali');

select * from meve_employee
where employe_name not in (
select employe_name 
from meve_works
where Company_name = 'Sonali');

select * from  meve_works
where employe_name not in (
select employe_name 
from meve_employe 
where Company_name = 'Sonali');

update meve_employe 
set city='Natore'
where employe_name='Arif';

delete from meve_employe
where employe_name='Sagor';

alter table meve_works add Manager varchar(50);
