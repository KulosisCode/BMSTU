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
    id_emp =   IntegerField(column_name='id_emp')
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
result = Employee.select(Employee.fio, Employee.birthday).\
        where(Employee.id > 1)
result_1 = In_out.select(In_out.id_emp, In_out.rdate).\
    where(In_out.id_io>1)        

print_query(result_1)