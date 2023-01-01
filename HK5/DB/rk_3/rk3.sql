-- TASK 1
-- create table
create table if not exists employee(
   id serial primary key,
   fio text,
   birthday date,
   depart text
);

select * from employee;

create table if not exists in_out(
   id_io serial primary key,
   id_emp int not null,
   rdate date,
   wday text,
   rtime time not null,
   rtype int check (rtype > 0  and rtype <3),
   foreign key (id_emp) references employee(id)
);

select * from in_out;

delete from in_out *;
drop table in_out;
drop table employee;

-- insert into table data

insert into employee(
   fio,
   birthday,
   depart
) values
   ('FIO1', '1996-09-25', 'IT'),
   ('FIO2', '1999-09-30', 'IT'),
   ('FIO3', '1990-09-25', 'Fin'),
   ('FIO4', '1997-09-15', 'Fin'),
   ('FIO5', '1995-09-25', 'IT'),
   ('FIO6', '1999-09-30', 'IT'),
   ('FIO7', '1990-09-10', 'Fin');


insert into in_out (id_emp,   rdate, wday, rtime, rtype)
values
   (1, '2022-12-14', 'Вторник', '9:05:00', 1),
   (1, '2022-12-14', 'Вторник', '9:20:00', 2),
   (1, '2022-12-14', 'Вторник', '9:20:00', 2),
   (1, '2022-12-14', 'Вторник', '9:20:00', 2),
   (1, '2022-12-14', 'Вторник', '9:20:00', 2),
   (1, '2022-12-14', 'Вторник', '9:25:00', 1),
   (2, '2022-12-14', 'Вторник', '9:36:00', 1),
   (2, '2022-12-14', 'Вторник', '18:36:00', 2),
   (2, '2022-12-15', 'Среда',   '9:05:00', 1),
   (2, '2022-12-15', 'Среда',   '17:10:00', 2),
   (3, '2022-12-18', 'Суббота', '10:00:00', 1),
   (5, '2022-12-17', 'Суббота', '10:00:00', 1),
   (5, '2022-12-17', 'Суббота', '12:00:00', 2),
   (5, '2022-12-17', 'Суббота', '14:00:00', 1),
   (6, '2022-12-17', 'Суббота', '7:00:00', 1);

-- FUNCTION : return employee didn't come "today"
create or replace function not_work(d date)
returns table(_fio text, _depart text)
language plpgsql
AS $$
BEGIN
   return query
   ( 
         select fio, depart from employee
         where fio not in(
            select employee.fio
            from employee join in_out on (employee.id = in_out.id_emp)
            where in_out.rdate = d
            group by fio)
       
   );
END
$$

SELECT * FROM not_work('2022-12-14');
drop function not_work(date);

-- TASK 2
--SQL

--Найти сотрудников, опоздавших сегодня меньше, чем на 5 минут
with first_time_in as (
   select distinct on (rdate, time_in) id_emp, rdate, min(rtime) OVER (PARTITION BY id_emp, rdate) as time_in
   from in_out
   where rtype = 1)
select employee.id, employee.fio, time_in
from first_time_in join employee on first_time_in.id_emp = employee.id
where rdate = '2022-12-15' and time_in <= '9:05' and time_in > '9:00'

--Найти сотрудников, которые выходили больше, чем на 10 минут
select DISTINCT id_emp
from employee join
   (
   select id_emp, rdate, rtime,
         rtype,
         lag(rtime) over (partition by id_emp, rdate order by rtime) as prev_time,
         rtime-lag(rtime) over (partition by id_emp, rdate order by rtime) as tmp_dur
      from in_out
      order by id_emp, rdate, rtime
      ) as small_durations
on employee.id = small_durations.id_emp
where small_durations.rdate = '2022-12-17'
and small_durations.tmp_dur > '00:10:00'
group by small_durations.id_emp
HAVING count(small_durations.id_emp) > 1

--Найти сотрудников бухгалтерии, приходивших на работу раньше 8:00         
with first_time_in as (
   select distinct on (rdate, time_in) id_emp, rdate, min(rtime) OVER (PARTITION BY id_emp, rdate) as time_in
   from in_out
   where rtype = 1)
select employee.id, employee.fio, time_in
from first_time_in join employee on first_time_in.id_emp = employee.id
where employee.depart = 'IT' and time_in <= '8:00'

###PYTHON:


from peewee import *
from time import *
from datetime import *
con = PostgresqlDatabase(
    database = "rk_3",
    user = "postgres",
    password = "haoasd",
    host = "localhost",
    port = "5432"
    )
class BaseModel(Model):
    class Meta:
        database = con
class Employee(BaseModel):
    id = IntegerField(column_name='id')
    fio = CharField(column_name='fio')
    birthday = DateField(column_name='birthday')
    depart = CharField(column_name='depart')
    class Meta:
        table_name = 'employee'
class In_out(BaseModel):
    id_io = IntegerField(column_name='id_io')
    #id_emp = ForeignKeyField(Employee, on_delete="cascade")
    id_emp = IntegerField(column_name='id_emp')
    rdate = DateField(column_name='rdate')
    wday = CharField(column_name='wday')
    rtime = TimeField(column_name='rtime')
    rtype = IntegerField(column_name='rtype')
    class Meta:
        table_name = 'in_out'
def print_query(query):
    u_b = query.dicts().execute()
    for elem in u_b:
        print(elem)

#Найти сотрудников, опоздавших сегодня меньше, чем на 5 минут
def task_2_1():
    dat = '2022-12-15'
    query = Employee\
        .select(Employee.id, Employee.fio)\
        .from_(In_out\
            .select(fn.Distinct(SQL('id_emp'), SQL('rdate')),
                    SQL('id_emp'),
                    SQL('rdate'),
                    fn.min(In_out.rtime).over(partition_by=[In_out.id_emp, In_out.rdate]).alias('time_in'))\
            .where(In_out.rtype==1)).alias('r')\
        .join(Employee, on=(Employee.id == SQL('id_emp')))\
        .where(SQL('time_in') > '09:00')\
        .where(SQL('time_in') <= '09:05')\
        .where(SQL('rdate') == dat)
    print_query(query)

#Найти сотрудников, которые выходили больше, чем на 10 минут
def task_2_2():
    now = datetime.now().year
    dt = '2022-12-17'
    query = In_out\
                .select(fn.Distinct(SQL('id_emp')))\
                .from_(
                    In_out\
                        .select(SQL('id_emp'),
                                SQL('rdate'),
                                SQL('rtime'),
                                SQL('rtype'),
                                fn.Lag(In_out.rtime).over(partition_by=[In_out.id_emp, In_out.rdate]).alias('prev_time'),
                                (In_out.rtime - fn.Lag(In_out.rtime).over(partition_by=[In_out.id_emp, In_out.rdate])).alias('tmp_dur'),
                                )\
                        .order_by(In_out.id_emp, In_out.rdate, In_out.rtime)
                ).alias('small_durations')\
        .join(Employee, on=(Employee.id==SQL('id_emp')))\
        .where(SQL('tmp_dur') > '00:10:00')\
        .where(SQL('rdate') == dt)\
        .group_by(SQL('id_emp'))\
        .having(fn.count(SQL('id_emp')) > 1)
    print_query(query)

#Найти сотрудников бухгалтерии, приходивших на работу раньше 8:00
def task_2_3():
    query = Employee\
    .select(fn.Distinct(Employee.id, Employee.fio), Employee.id, Employee.fio)\
    .from_(In_out\
        .select(fn.Distinct(SQL('id_emp'), SQL('rdate')),
                SQL('id_emp'),
                SQL('rdate'),
                fn.min(In_out.rtime).over(partition_by=[In_out.id_emp, In_out.rdate]).alias('time_in'))\
        .where(In_out.rtype==1)).alias('r')\
    .join(Employee, on=(Employee.id == SQL('id_emp')))\
    .where(Employee.depart == 'IT')\
    .where(SQL('time_in') <= '8:00')
    print_query(query)

print("\nНайти сотрудников, опоздавших сегодня меньше, чем на 5 минут")
task_2_1()
print("\nНайти сотрудников, которые выходили больше, чем на 10 минут")
task_2_2()
print("\nНайти сотрудников бухгалтерии, приходивших на работу раньше 8:00")
task_2_3()
