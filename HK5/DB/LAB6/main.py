#LAB 6 DATABASE
import psycopg2
try:
    task = psycopg2.connect(
        database = "housewares_db",
        user = "postgres",
        password = "haoasd",
        host = "localhost",
        port = "5432"
    )
except Exception as e:
        print(f'Error occurred : {e}')

print("Successfully connection!")

def result_output(result):
    for note in result:
        for var in note:
            print("{:^30}".format(var), end='')
        print()

# Выполнить скалярный запрос
def task1():
    print("Youngest customer list:")
    cursor = task.cursor()
    cursor.execute("select * from customers where customers.age in(select min(age) from customers)")
    result = cursor.fetchall()
    result_output(result)

# Выполнить запрос с несколькими соединениями (JOIN)

def task2():
    print("Housewares that cost less than 5000 and are purchased by people over 20 years old")
    cursor = task.cursor()
    cursor.execute("select housewares.name, housewares.price, customers.age \
                    from housewares join customers on housewares.id_customer = customers.id_customer \
                    where housewares.price < 5000\
                    and customers.age < 20")

    result_output(cursor.fetchall())

# Выполнить запрос с ОТВ(CTE) и оконными функциями
def task3():
    print("Show average, min and max values price by diffrent group")
    cursor = task.cursor()
    cursor.execute("select id_brand, id_store, price, \
                    avg(price) over (partition by id_brand) as avg_brand_price, \
                    min(price) over (partition by id_brand order by id_store) as min_brand_price, \
                    max(price) over (partition by id_store) as max_store_price \
                    from housewares")
    result_output(cursor.fetchall())

# Выполнить запрос к метаданным
def task4():
    print("Show data in table brands")
    cursor = task.cursor()
    cursor.execute("select column_name, data_type \
                    from information_schema.columns\
                    where table_name = 'brands'")
    result_output(cursor.fetchall())

# Вызвать скалярную функцию (написанную в третьей лабораторной работе)\
def task5():
    print("Youngest person in the list of same name")
    cursor = task.cursor()
    cursor.execute("select * from customers\
                    where customers.first_name = 'Benjamin' \
                    and customers.age = min_age('Benjamin')")
    result_output(cursor.fetchall())

# Вызвать многооператорную или табличную функцию (написанную в третьей лабораторной работе)
def task6():
    print("Brand that have more housewares than 'Mack LLC'")
    cursor = task.cursor()
    cursor.execute("select * from more_housewares('Mack LLC')")
    result_output(cursor.fetchall())

# Вызвать хранимую процедуру (написанную в третьей лабораторной работе)
def task7():
    print("Update country columns of brand 'Carter LLC'")
    cursor = task.cursor()
    cursor.execute("call update_brand_country('Carter LLC')")
    cursor.execute("select * from brands where brand_name = 'Carter LLC'")
    result_output(cursor.fetchall())

# Вызвать системную функцию или процедуру
# Имя пользователя в текущем контексте выполнения
def task8():
    print("Username in the current execution context")
    cursor = task.cursor()
    cursor.execute("select * from current_user")
    result_output(cursor.fetchall())

# Создать таблицу в базе данных, соответствующую тематике БД

def task9():
    print("Make a table for expired housewares")
    cursor = task.cursor()
    try:
        cursor.execute("drop table if exists expired;")
        cursor.execute("create table expired( \
                id int generated always as identity primary key, \
                name text not null, price int not null);")
        task.commit()
    except Exception:
        print("Failed make table")
        task.rollback()


# Выполнить вставку данных в созданную таблицу с использованием инструкции INSERT или COPY

def task10():
    try:
        print("Insert data in table expired")
        cursor = task.cursor()
        cursor.execute("insert into expired(name, price) values \
                        ('Big TV', 1500), \
                        ('Moonlike light', 1000), \
                        ('Telephone',2000); \
                        select * from expired;")
        result_output(cursor.fetchall())
        task.commit()
    except:
        task.rollback()

def menu():
  print("------------------MENU------------------")
  print("1. Выполнить скалярный запрос")
  print("2. Выполнить запрос с несколькими соединениями (JOIN)")
  print("3. Выполнить запрос с ОТВ(CTE) и оконными функциями")
  print("4. Выполнить запрос к метаданным")
  print("5. Вызвать скалярную функцию (написанную в третьей лабораторной работе)")
  print("6. Вызвать многооператорную или табличную функцию (написанную в третьей лабораторной работе)")
  print("7. Вызвать хранимую процедуру (написанную в третьей лабораторной работе)")
  print("8. Вызвать системную функцию или процедуру")
  print("9. Создать таблицу в базе данных, соответствующую тематике БД")
  print("10. Выполнить вставку данных в созданную таблицу с использованием инструкции INSERT или COPY")
  print("0. Выход")
  print("----------------------------------------")


def input_choice():
    choice = -1
    while choice < 0 or choice > 10:
        try:
            choice = int(input("> "))
            if choice < 0 or choice > 10:
                print("Введите число от 0 до 10")
        except Exception:
            print("Введите число от 0 до 10")
    return choice


while True:
    menu()
    choice = input_choice()
    if  choice == 1:
        task1()
    elif choice == 2:
        task2()
    elif choice == 3:
        task3()
    elif choice == 4:
        task4()
    elif choice == 5:
        task5()
    elif choice == 6:
        task6()
    elif choice == 7:
        task7()
    elif choice == 8:
        task8()
    elif choice == 9:
        task9()
    elif choice == 10:
        task9()
        task10()
    else:
        break