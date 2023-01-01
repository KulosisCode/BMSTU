from DEFINITION import *
from PATH import *
from random import randint, shuffle, choice
import datetime
import codecs
from faker import Faker
import csv

def generate_customers():
    sexs = ['male', 'female']
    # out_file_database = open(PATH_CUSTOMERS_DATABASE, "w", encoding='utf8')
    with open(PATH_CUSTOMERS_DATABASE, "w", newline='') as file:
        out_file_database = csv.writer(file,delimiter=',')
        for i in range(MAX_SIZE_DATABASE):
            id = i + 1
            first_name = faker.first_name()
            last_name = faker.last_name()
            age = randint(YOUNGEST_AGE, OLDER_AGE)
            sex = choice(sexs)
            city = faker.city()

            out_file_database.writerow(
                [id, first_name, last_name, sex, age, city]
            )

            # line = "{0};{1};{2};{3};{4};{5}\n".format(id, first_name, last_name, sex, age, city)
            # out_file_database.write(line)
        # out_file_database.close()

def generate_types():
    typenames = ['Kitchen', 'Living room', 'Bathroom', 'Bedroom']
    descriptions = ['just bought','out of date', 'long-term use', 'good', 'damaged']
    materials = read_all_file(PATH_CHARACS)
    with open(PATH_CHARACS_DATABASE, "w", newline='') as file:
        out_file_database = csv.writer(file, delimiter=',')
        for i in range(MAX_SIZE_DATABASE):
            id = i + 1
            type_name = choice(typenames)
            description = choice(descriptions)
            material =  materials[randint(MIN_MATERIAL - 1, MAX_MATERIAL - 1)]

            out_file_database.writerow(
                [id, type_name, description, material]
            )

def generate_brands():
    with open(PATH_BRANDS_DATABASE, "w", newline='') as file:
        out_file_database = csv.writer(file, delimiter=',')
        for i in range(MAX_SIZE_DATABASE):
            id =  i + 1
            brand_name = faker.company()
            country = faker.country()
            fouder = faker.name()

            out_file_database.writerow(
                [id, brand_name, country, fouder] 
            )

def generate_stores():
    with open(PATH_STORES_DATABASE, "w", newline='') as file:
        out_file_database = csv.writer(file,delimiter=',')
        for i in range(MAX_SIZE_DATABASE):
            id = i + 1
            name = faker.company()
            address = faker.address()
            id_brand = randint(MIN_SIZE_DATABASE, MAX_SIZE_DATABASE)
            email = faker.email()

            out_file_database.writerow(
                [id, name, address, id_brand, email]
            )
            
def generate_housewares():
    names = read_all_file(PATH_HOUSEWARES)
    with open(PATH_HOUSEWARES_DATABASE, "w", newline='') as file:
        out_file_database = csv.writer(file, delimiter=',')
        for i in range(MAX_SIZE_DATABASE):
            id = i + 1
            #name = faker.text(max_nb_chars=10)[:-1]
            name = names[randint(0, MAX_HOUSEWARE - 1)]
            price =  randint(MIN_PRICE, MAX_PRICE)
            date_sale = faker.date_time()
            id_type = randint(MIN_SIZE_DATABASE, MAX_SIZE_DATABASE)
            id_brand = randint(MIN_SIZE_DATABASE, MAX_SIZE_DATABASE)
            id_customer = randint(MIN_SIZE_DATABASE, MAX_SIZE_DATABASE)
            id_store = randint(MIN_SIZE_DATABASE, MAX_SIZE_DATABASE)

            out_file_database.writerow(
                [id, name, price, date_sale, id_type, id_brand, id_customer, id_store]
            )

def read_all_file(PATH):
    with open(PATH, "r", encoding="utf-8") as file_data:
        data = [line.strip() for line in file_data] 
    return data

if __name__ == '__main__':
    faker = Faker()
    generate_customers()
    generate_types()
    generate_brands()
    generate_stores()
    generate_housewares()
