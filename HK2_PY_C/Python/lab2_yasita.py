
from prettytable import PrettyTable
import time
import random

#Сортировка вставками
def insertionsort(arr):
	for i in range(1,len(arr)):
		cur=arr[i]
		j=i-1
		while j>=0 and cur<arr[j]:
			arr[j+1]=arr[j]
			j=j-1
		arr[j+1]=cur
	return arr

#Упорядоченный массив
def count1(arr):
    temp_arr = arr.copy()
    t0 = time.time()
    insertionsort(temp_arr)
    return round((time.time() - t0) * 1000, 5)

#Случайный массив
def count2(arr):
    temp_arr = arr.copy()
    random.shuffle(temp_arr)
    t0 = time.time()
    insertionsort(temp_arr)
    return round((time.time() - t0) * 1000, 5)

#Обратно упорядоченный массив
def count3(arr):
    temp_arr = sorted(arr)
    temp_arr.reverse()
    t0 = time.time()
    insertionsort(temp_arr)
    return round((time.time() - t0) * 1000, 5)


n_1 = int(input('Введите N_1 :'))
n_2 = int(input('Введите N_2 :'))
n_3 = int(input('Введите N_3 :'))

arr1 = [i for i in range(n_1)]
arr2 = [i for i in range(n_2)]
arr3 = [i for i in range(n_2)]

print()
print('Calculate time (milisec.)')
print('Метод простык вставок ')
myTable = PrettyTable(["Тип","N_1", "N_2", "N_3"])

myTable.add_row(["Упорядоченный массив", count1(arr1), count1(arr2), count1(arr3)])

myTable.add_row(["Случайный массив", count2(arr1), count2(arr2), count2(arr3)])

myTable.add_row(["Обратно упорядоченный массив", count3(arr1), count3(arr2), count3(arr3)])

print(myTable)
