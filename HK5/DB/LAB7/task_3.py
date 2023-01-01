from peewee import *

db = PostgresqlDatabase(
    database = "housewares_db",
    user = "postgres",
    password = "haoasd",
    host = "localhost",
    port = "5432"
    )

class BaseModel(Model):
    class Meta:
        database = db

class Brand(BaseModel):
    id_brand = PrimaryKeyField(column_name = 'id_brand')
    brand_name = CharField(column_name = 'brand_name')
    country = CharField(column_name = 'country')
    founder = CharField(column_name = 'founder')

    class Meta:
        table_name = 'brands'

class Store(BaseModel):
    id_store = PrimaryKeyField(column_name = 'id_store')
    name = CharField(column_name = 'name')
    address = CharField(column_name = 'address')
    id_brand = IntegerField(column_name = 'id_brand')
    email = CharField(column_name = 'email')

    class Meta:
        table_name = 'stores'

def query_1():
    result = Brand.select(Brand.id_brand, Brand.brand_name,  Brand.country, Brand.founder).\
        where(Brand.id_brand > 995)
    for row in result.namedtuples():
        print("{:^30}{:^30}{:^30}".format(row.id_brand,row.brand_name, row.country, row.founder))

def query_2():
    result = Brand.select(Brand.id_brand, Brand.brand_name, Store.name).\
            join(Store, on=(Brand.id_brand == Store.id_brand)).\
            where(Store.id_store < 200)
    for row in result.namedtuples():
        print("{:^30}{:^30}{:^30}".format(row.id_brand, row.brand_name, row.name))

def print_brands():
    print("\nBrands:")
    result = Brand.select(Brand.id_brand, Brand.brand_name, Brand.country, Brand.founder)
    for row in result.namedtuples():
        print("{:^30}{:^30}{:^30}{:^30}".format(row.id_brand, row.brand_name, row.country, row.founder))

# def print_stores(id_brand):
#     print("\nStores:")
#     result = Store.select().where(Store.id_brand == id_brand)
#     for row in result.namedtuples:
#         print("{:^30}{:^30}{:^30}{:^30}{:^30}".format(row.id_store, row.name, row.address, row.id_brand, row.email))

def adding(id_brand, brand_name, country, founder):
    try:
        Brand.create(id_brand = id_brand, brand_name = brand_name,\
                         country = country,founder = founder)
        print("Added Success!")
    except Exception as exc:
        print(exc)

def updating(brand_name, country):
    try:
        brands = Brand.select().where(Brand.brand_name == brand_name)
        for brand in brands:
            brand.country = country
            brand.save()
        print("Updated Success!")
    except Exception as exc:
        print(exc)

def deleting(brand_name):
    try:
        brand = Brand.get(brand_name = brand_name)
        brand.delete_instance()
    except Exception as exc:
        print(exc)
    
def query_3():
    print("-- Добавление в таблицу")
    id_brand = int(input("id_brand: "))
    brand_name = input("brand_name: ")
    country = input("country: ")
    founder = input("founder:")

    adding(id_brand, brand_name, country,founder)
    print_brands()

    print("-- Обновление таблицы")
    brand_name = input("brand_name: ")
    country = input("country: ")

    updating(brand_name, country)
    print_brands()

    print("-- Удаление из таблицы")
    brand_name = input("brand_name: ")
    print_brands()
    deleting(brand_name)
    print_brands()

def query_4():
    try:
        cursor = db.cursor()
        print("Обновить страну бренда")
        cursor.execute("call update_brand_country('Carter LLC')")
        print_brands()
    except Exception as exc:
        print(exc)

def task_3():
    print("1.All brands have id_brand > 995")
    query_1()

    print("2.Brand, which have id_store < 200")
    query_2()

    print("3. 3 Query")
    query_3()

    print("4. Получение доступа к данным с помоью хранимой процедуры")
    query_4()