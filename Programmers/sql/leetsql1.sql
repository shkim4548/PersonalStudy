--175. Combine Two Table
i.	ALTER TABLE member ADD birth DATETIME]

ALTER TABLE member ADD score int AFTER NUMBER

ALTER TABLE member DROP birthday

ALTER TABLE member MODIFY name VARCHAR(10)

CREATE TABLE tb1(
    `name`, RECORD_TYPE, DEFAULT NULL;
    ...
)

INSERT INTO tb1 record VALUES(DATA);


create view v1 as select name, age from tb1L

select * from v1;

update v1 set name='주임 조수혁' where name='조수혁';

select * from v1;

select * from tb;

create view v2
as select tb.number, tb1L.name, tb.sales
from tb
join tb1L
using(number)
where tb.sales>=100;

select * from v2;

update tb set sales=777 where sales=54;

select * from v2

insert into v1 values('임시직 이정희', 18);

select * from v1;

select * from tb1L;

create view v3 as select number, sales from tb where sales>=100;

select * from v3;

insert into v3 values('테스트',50);

select number, sales from tb;

create view v4 as select number, sales from tb where sales>=100 with check option;

insert into v4 values('테스트',50);

create or replace view v1 as select now();

alter view v1 as select name, age from tb;

drop view if exists v1;

DELIMITER //
create procedure pr1()
BEGIN
select * from tb;
select * from tb1L;
end
//
DELIMITER;

DELIMITER //
create procedure pr2(d INT)
BEGIN
select * from tb where sales >= d;
END
//
DELIMITER;

call pr2(200);

DELIMITER //
CREATE FUNCTION fu1(height INT) RETURNS DOUBLE
BEGIN
RETURN height * height *22 /10000;
END
//
DELIMITER;

DELIMITER //
CREATE FUNCTION fu2() RETURNS DOUBLE
BEGIN
DECLARE r DOUBLE;
SELECT AVG(sales) INTO r FROM tb;
RETURN r;
END
//
DELIMITER;

DELIMITER
//
CREATE TRIGGER tr1 BEFORE DELETE ON tb FOR EACH ROW
BEGIN
INSERT INTO tb1M VALUES(OLD.number, OLD.name, OLD.age);
END
//
DELIMITER;

DROP TRIGGER tr1;