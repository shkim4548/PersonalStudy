select * from tb;

start transaction;

delete from tb;

select * from tb;

ROLLBACK;

select * from tb;

COMMIT;

set autocommit=0;

insert into tb values('test', 555,555);

select * from tb;

rollback;

set autocommit=1;

create table tb1(
    `number` varchar(30) default null,
    `sales` varchar(30) default null,
    `month` varchar(30) default null
);

load data infile '/var/html/t.csv' into table tbk fields terminated by ',';