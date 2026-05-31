create database LabEx2;
use LabEx2;

create table meve_employee(employe_name varchar(50),Street varchar(50),city varchar(50));

insert into  meve_employee(employe_name,Street ,city) values

('Arif','51 Upasahar','Rajshahi'),
('Sumon','52 East','Moynamati'),
('Sagor','Neemgachi','Rajshahi'),
('Abdul','Binodpur','Rajshahi'),
('Himesh','Nazru Avaneu','Dhaka'),
('Amirul','ChawkBazar','sylhet'),
('Sajib','99 Worth','Chittagong');

select *from meve_employee;

drop table meve_employee;

create table meve_works(employe_name varchar(50),Company_name varchar(50),Salary int);

insert into  meve_works(employe_name,Company_name ,Salary) values
('Sumon','Agrani',12000),
('Abdul','Sonali',13000),
('Himesh','Agrani',6000),
('Amirul','Sonali',20000),
('Sagor','Sonali',8000),
('Arif','Janata',13000),
('Sajib','Janata',9000);

select *from meve_works;

drop table meve_works;
--2
select employe_name 
from meve_employee
where city='Rajshahi';
--3
select employe_name,Street 
from meve_employee
where city='Rajshahi';
--4
select employe_name,Company_name
from meve_works
where Company_name='Sonali';

select employe_name,Company_name
from meve_works
where Company_name='Agrani' ;

select employe_name,Company_name
from meve_works
where Company_name='Janata';
--5
select employe_name,Salary
from meve_works
where Company_name='Sonali';

select employe_name,Salary
from meve_works
where Company_name='Agrani';

select employe_name,Salary
from meve_works
where Company_name='Jananta';
--6
select employe_name,Salary
from meve_works
where Salary =12000;

select employe_name,Salary
from meve_works
where Salary >=12000;

select employe_name,Salary
from meve_works
where Salary < 12000;
--7
select employe_name,Company_name,Salary
from meve_works
where Salary < 12000;

select employe_name,Company_name,Salary
from meve_works
where Salary >= 12000;

select employe_name,Company_name,Salary
from meve_works
where Salary >= 12000;

select employe_name,Company_name,Salary
from meve_works
where Salary < 12000;
--8
select employe_name, street, City 
from meve_employee
where employe_name in(
select employe_name from meve_works
where Company_name = 'Agrani');
--9
select employe_name, street, City 
from meve_employee
where employe_name in(
select employe_name from meve_works
where salary >= 10000);
--10
select employe_name,Company_name, salary 
from meve_works
where employe_name in(
select employe_name from meve_employee
where City = 'Rajshahi');
--11
select employe_name, street, City,
       (select company_name 
        from meve_works 
        where employe_name = meve_employee.employe_name) as company_name
from meve_employee
where employe_name IN (
    select employe_name
    from meve_works
    where salary >= 10000
);
--12
select employe_name, street, City 
from meve_employee
where employe_name in(
select employe_name from meve_works
where company_name = 'Sonali' and salary >= 10000);
--13
select * from meve_employee
where employe_name not in (
select employe_name from meve_works
where Company_name = 'Sonali');
--14
update meve_employee
set City = 'Natore'
where employe_name = 'Arif';
--15
update meve_works
set salary = salary * 1.10
where company_name = 'Agrani';
--16
delete from meve_employee
where employe_name = 'Sagar';
--17
alter table meve_works
add manager varchar(50);










