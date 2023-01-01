from py_linq import *
import csv

class Brand():
    id_brand = int()
    brand_name = str()
    country = str()
    founder = str()

    def __init__(self,id_brand,brand_name,country,founder):
        self.id_brand = id_brand
        self.brand_name = brand_name
        self.country = country
        self.founder =founder
    
    def get(self):
        return {'id_brand': self.id_brand, 'brand_name': self.brand_name,
                'country': self.country, 'founder': self.founder}

def get_brand_array(filename):
    file = open(filename, 'r')
    reader = csv.reader(file, delimiter=',')
    brands = []
    for line in reader:
        elems = [x for x in line]
        brands.append(Brand((elems[0]), elems[1], elems[2], elems[3]).get())
    return brands

class Store():
    id_store = int()
    name = str()
    address = str()
    id_brand = int()
    email = str()
    
    def __init__(self,id_store,name,address,id_brand,email):
        self.id_store = id_store
        self.name = name
        self.address = address
        self.id_brand = id_brand
        self.email = email
    def get(self):
        return {'id_store': self.id_store, 'name': self.name, 'address': self.address, 
                'id_brand': self.id_brand, 'email': self.email}

def get_store_array(filename):
    file = open(filename, 'r')
    reader = csv.reader(file, delimiter=',')
    stores = []
    for line in reader:
        elems = [x for x in line]
        stores.append(Store(int(elems[0]), elems[1], elems[2], int(elems[3]), elems[4]).get())
    return stores

def query_1(brands):
    return brands.select(lambda x: {x['brand_name']})

def query_2(brands):
    return brands.where(lambda x: x['country'] == 'Bhutan').select(lambda x: {x['brand_name'], x['founder']})

def query_3(brands):
    return brands.group_by(key_names=['country'], key=lambda x: x['country']).select(lambda h: { 'key': h.key.country, 'count':h.count()})

def query_4(brands, stores):
    res = brands.join(stores, lambda b: b['id_brand'], lambda s: s['id_brand'])
    return res

def query_5(stores):
    return stores.where(lambda x: x['id_store'] < 50).select(lambda x: x['id_brand']).min()

def print_res(res, msg):
    print(msg)
    count = 8
    for i in range(count):
        if not res[i]: break
        print(res[i])
    print()

def task_1():
    brands = Enumerable(get_brand_array("D:\PROGRAM\HK5\DB\LAB1\csv\listbrands.csv"))
    stores = Enumerable(get_store_array("D:\PROGRAM\HK5\DB\LAB1\csv\stores.csv"))

    print_res(query_1(brands), "1.Show brand_name")
    print_res(query_2(brands), "2.Brand & founder info from Bruhtan")
    print_res(query_3(brands), "3.Amount country")
    print_res(query_4(brands, stores), "4.Join table brands & stores")
    print( "5.Max id_brand of store have id_store < 50\n", query_5(stores))
