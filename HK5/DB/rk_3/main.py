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

