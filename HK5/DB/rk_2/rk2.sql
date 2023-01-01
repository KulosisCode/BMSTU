--TASK 1

-- create database
drop database  if exists  rk_2;
create database rk_2;

-- create table

-- виды работ.
create table if not exists type_of_jobs
(
    id int primary key,
    name_jobs text,
    labor_costs int, -- трудозатраты.
    equipment text -- необходимое оборудование.
);

-- исполнитель.
create table if not exists executor
(
    id int primary key,
    fio text,
    year_of_birth int,
    experience int, -- стаж (кол-во лет)
    phone text
);

-- заказчик.
create table if not exists customer
(
    id int primary key,
    fio text,
    year_of_birth int,
    experience int, -- стаж
    phone text
);

-- развязочная таблица для type_of_jobs и executor.
create table if not exists type_of_jobs_executor
(
    id_type_of_jobs int,
    foreign key (id_type_of_jobs) references type_of_jobs(id),
    id_executor int,
    foreign key (id_executor) references executor(id)
);

-- развязочная таблица для executor и customer
create table if not exists executor_customer
(
    id_executor int,
    foreign key (id_executor) references executor(id),
    id_customer int,
    foreign key (id_customer) references customer(id)
);

-- развязочная таблица для type_of_jobs и customer.
create table if not exists type_of_jobs_customer
(
    id_type_of_jobs int,
    foreign key (id_type_of_jobs) references type_of_jobs(id),
    id_customer int,
    foreign key (id_customer) references customer(id)
);


insert into type_of_jobs(id, name_jobs, labor_costs, equipment)
values
(1,   'код на с',   500, 'компьютер'),
(2,   'картина', 350000,   'кисточки'),
(3,   'код на sql', 100000,'компьютер'),
(4,   'преподавтель по физике', 400000, 'тетрадка');

insert into executor(id, fio, year_of_birth, experience, phone)
values
   (1,'pasha cool', 1985, 20, '79798885543'),
   (2,'masha cook', 1969, 30, '79793335543'),
   (3,'hmmm hm', 1972, 5, '79798884421'),
   (4,'dasha cool', 1975, 23, '79796665543'),
   (5,'pork meat', 1993, 7, '79793335543');

insert into customer(id, fio, year_of_birth, experience, phone)
values
   (1,'mama no', 1974, 3, '79798884400'),
   (2,'olga no', 1952, 50, '79798884433'),
   (3,'volk polk', 1955, 23, '79796635543'),
   (4,'solo home', 1997, 4, '78883335543');

select * from type_of_jobs ;
select * from executor ;
select * from customer ;

insert into type_of_jobs_executor
values
(1,   2),
(1,   3),
(1,   5),
(2,   3),
(3, 1),
(4,   5),
(1,   4);

insert into type_of_jobs_customer
values
(1,   1),
(2,   2),
(3,   3),
(4,   1);

insert into executor_customer
values
(1,   2),
(3,   4),
(1,   1),
(5,   1),
(5,   2),
(4,   3);

select * from type_of_jobs_executor ;
select * from type_of_jobs_customer;
select * from executor_customer ;


--TASK 2
-- 3 query sql

-- 1. инструкция select, использующая предикат сравнения.
-- вывести всю информацию о исполнителях
-- год рождения которых меньше 1995.
select *
from executor
where year_of_birth < 1995;

-- 2. инструкцию, использующую оконную функцию.
-- вывести информацию о виде работы,
-- добавляя столбец cnt, в котором показано
-- сколько сумерно тратится (сумма трудозатрат)
-- на работу с каким-то оборудованием.
select id, name_jobs, labor_costs, equipment, sum(labor_costs) over(partition by equipment) cnt
from type_of_jobs
order by cnt;

-- 3. инструкция select, использующая вложенные коррелированные
-- подзапросы в качестве производных таблиц в предложении from.
-- вывести всю информацию о исполнителе
-- у которой стаж работы больше чем средний стаж работы.
select *
from executor
where  experience >
(
    select avg(experience)
    from executor
);


--TASK 3
--создать хранимую процедуру с входным параметром, которая выводит
-- имена хранимых процедур, созданных с параметром with recompile, в
-- тексте которых на языке sql встречается строка, задаваемая параметром
-- процедуры. созданную хранимую процедуру протестировать.
create or replace procedure info_routine3
(
    str varchar(32)
)
as '
declare
    elem record;
begin
    for elem in
        select *
        from information_schema.routines
             -- чтобы были наши схемы.
        where specific_schema = ''public''
        and routine_type = ''procedure''
        and routine_definition like concat(''%'', str, ''%'')
    loop
        raise notice ''elem: %'', elem;
    end loop;
end;
' language plpgsql;

call info_routine3('select');

select *
from information_schema.routines
where specific_schema = 'public';
