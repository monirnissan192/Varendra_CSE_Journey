create database Lab10;
use Lab10;
--Parent table
create table Authors(
Author_Id int not null primary key,
Author_Name varchar(25)
);
Select * from Authors;

create table Books(
 BookID int primary key not null,
 BookTittle varchar(50),
 Author_Id int,
 foreign key(Author_Id) references Authors(Author_Id)
 on delete cascade,
 foreign key(Author_Id) references Authors(Author_Id)
 on update cascade

 );
 drop table  Books;
 --Parent table Authors -Id ID delete then this this delete from Parent table
 delete Authors
 where Author_Id = 2

 select * from Books;

 create table Publisher(
 PublisherID int primary key not null,
 PublisherName varchar(50),
 Author_Id int,
 foreign key(Author_Id) references Authors(Author_Id)
 on update cascade
 );
 select *from Publisher;
 drop table Publisher;
 update Authors
 set Author_Id=7
Where Author_Id=3

Select * from Authors;
select * from Books;
 select *from Publisher;
