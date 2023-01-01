import json
import psycopg2
from task_1 import Brand

def get_json_brand(task):
    cursor = task.cursor()
    cursor.execute("copy (select row_to_json(b) from brands b) \
                    to 'D:\PROGRAM\HK5\DB\LAB5\ brands.json';")
    print("Create JSON for table brands - successfully!")
    cursor.close()

def data_output(data, keys):
    for key in keys:
        print("{:^30}".format(str(data[key])),end='')
    print()

def read_json(filename):
    file = open(filename, 'r')
    for line in file:
        data = json.loads(line)
        keys = data.keys()
        data_output(data, keys)
    file.close()

def update_json(filename, brand_name, country):
    file = open(filename, 'r')
    data = list()
    for line in file:
        data.append(json.loads(line))
    keys = data[0].keys()
    for elem in data:
        if elem['brand_name'] == brand_name:
            data_output(elem, keys)
            elem['country'] = country
            data_output(elem, keys)
    file.close()
    file = open(filename, 'w')
    for elem in data:
        file.write(json.dumps(elem, ensure_ascii=False) + '\n')
    file.close()

def insert_into_json(filename, data):
    file = open(filename, 'a')
    file.write(json.dumps(data, ensure_ascii=False) + '\n')
    file.close()

def task_2():
    task = psycopg2.connect(
    database = "housewares_db",
    user = "postgres",
    password = "haoasd",
    host = "localhost",
    port = "5432"
    )

    get_json_brand(task)
    file_name = 'D:\PROGRAM\HK5\DB\LAB5\ brands.json'
    while True:
        command = -1
        while command < 0 or command > 3:
            command = int(input("Command> "))
        if command == 1:
            print("1. Чтение файла JSON")
            read_json(file_name)
        elif command == 2:
            print("2. Обновление JSON документ(Изменить страну бренда)")
            brand = input("Brand name: ")
            country = input("Name of country: ")
            update_json(file_name, brand, country)
        elif command == 3:
            print("3. Добавление в JSON документ")
            id_brand = input("id_brand: ")
            brand_name = input("Brand name: ")
            country = input("Country name: ")
            founder = input("Founder: ")

            insert_into_json(file_name, Brand(id_brand, brand_name, country, founder).get())
        else:
            break
    task.close()
