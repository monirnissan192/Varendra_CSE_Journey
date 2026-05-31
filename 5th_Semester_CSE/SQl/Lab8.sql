create database Lab8;
use Lab8;
create table demo1(
Id int,
Name Varchar(25),
Designation varchar(25),
Salary int
);
insert into demo1 (Id,Name,Designation,Salary)values
(1,'Sara','CEO',15000),
(2,'Jara','Manager',17000),
(3,'Samor','PO',22000),
(4,'Sara','Manager',18000);

drop table demo1

create procedure P1
as
begin
Select *From demo1
end
execute P1
--Procedure Drop Querry
drop procedure P1

create procedure P2
@Id int,
@Name varchar(25)
as
begin
Select Id,Name from demo1
where Id=@Id and Name = @Name
end
--When i execute wrong information then  i see this one  no output...here Designation replace the Name
--execute P2 1,'CEO'
execute P2 1,'Sara'
--Here the required output is come 

---select count(*)
/*from demo1
where Designation ='Manager'
My Output:2
 
At this Moment we are gonna See this output using Parameter this parameter is mainly output parameter
*/

create procedure P3
@Designation varchar(25),
@result int output
as
begin
Select @result=count(*)
from demo1
where Designation=@Designation
end

declare @CountTotal int
Execute P3'Manager',@CountTotal output
print @CountTotal

drop procedure P3


create procedure P5
@Salary int,
@result int output
as
begin
Select @result
from demo1
where Salary=@Salary
end
declare @CountTotal int
Execute P5 22000,@CountTotal output
print @CountTotal

--To see Stored Procedure Source code then use sp_helptext  
sp_helptext P3
sp_helptext P2
sp_helptext P1

--Encryption for injection Attack Stored Producer Avoid 
create procedure P4
@Designation varchar(25),
@result int output
with encryption
as
begin
Select @result=count(*)
from demo1
where Designation=@Designation
end

declare @CountTotal int
Execute P4 'Manager',@CountTotal output
print @CountTotal

sp_helptext P4

-- One table base how much Stored Procedure are using thats Mainly Show sp_depends
sp_depends P3
sp_depends P4
sp_depends P2
sp_depends P1

--here P3,P4  Stored Procedure Using Desination
--here 2 Stored Procedure Using Id ,Name
--here 1 Stored Procedure Using Id ,Name,Designation,Salary

--Now I am gonna stored Procedure Detials  sp_help

sp_help P3
sp_help P4
sp_help P2
sp_help P1

--I should one thing when we edit body part this time we use alter keyword the replace of create keyword because i know Stored procedures are precompiled
--Compile once no need to do it again that's why i use alter Keyword to replace memeory and add new Value
