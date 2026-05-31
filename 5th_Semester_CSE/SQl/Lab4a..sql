create database Lab;
use Lab;

create table Student(Roll char(50),Name varchar(50),Dept varchar(50),Year varchar(50),Semester varchar(50));

 insert into Student (Roll,Name,Dept,Year,Semester) values

 ('06543201','Rahim','BBA','2nd','1st'),
 ('06543202','Karim','ICE','2nd','1st'),
 ('06543203','Motin','CSE','1st','2nd'),
 ('05654456','Swadhin','CSE','1st','2nd'),
 ('05654457','Hena','BBA','4th','2nd'),
 ('05654458','Sohag','CSE','3rd','1st');

 select * from Student;

 create table Student_info(Roll char(50),Name varchar(50),Father_Name varchar(50),Address varchar(50),Mobile varchar(50));

 insert into Student_info (Roll,Name,Father_Name,Address,Mobile) values

 ('06543201','Rahim','Ataur','Rajshahi','01719201233'),
 ('06543202','Karim','Tareq','Dhaka','01719202020'),
 ('06543203','Motin','Rahman','Khulna','0171920678'),
 ('05654456','Swadhin','Fazlu','Rajshahi','01719204584'),
 ('05654457','Hena','Rahman','Rajshahi','01119212020'),
 ('05654458','Sohag','Faizul','Natore','01719202222');

 select * from Student_info;

 --i
 select Name
 from Student
 where Semester ='1st';

 select Name
 from Student
 where Year ='2nd';

 select Name
 from Student
 where Dept='CSE';

 select Name
 from Student
 where Roll='06543201';

 --ii
 select Name,Address,Mobile
 from Student_info
 where Father_Name='Rahman';

  select Name,Address,Mobile
 from Student_info
 where Mobile='01719202020';


  select Name,Address,Mobile
 from Student_info
 where Address='Rajshahi' and Father_Name='Rahman';
 
  select Name,Address,Mobile
 from Student_info
 where Roll='05654456';

