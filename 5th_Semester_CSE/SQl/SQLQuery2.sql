create  database demoDB1;
use demoDB1;

create table Student(
S_ID int,Names Varchar(50),
CGPA float
);

insert into Student(S_ID, Names, CGPA) values

(232311162,'Oheduzzaman Ornob',3.72),

(232311163,'Al Shahriar',2.99),

(232311191,'Nahian Tasmiah',3.31),

(232311192,'Monir Nissan',3.65);


select * from Student;

--drop table Student;
