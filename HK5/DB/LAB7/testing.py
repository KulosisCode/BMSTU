import csv
file = open('D:\PROGRAM\HK5\DB\LAB1\csv\stores.csv', 'r')
reader = csv.reader(file, delimiter=',')
brands = []
for line in reader:
    # elems = line.split(';')
    elems = [x for x in line]
    print(int(elems[0]), elems[1], elems[2], int(elems[3]),elems[4])
    #brands.append(Brand((elems[0]), elems[1], elems[2], elems[3]).get())

# reader = csv.reader(file, delimiter=',')
# for line in reader:
#     print(line)