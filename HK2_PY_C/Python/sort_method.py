# Чыонг Ван Хао - ИУ7и-21Б
# Lab_2 - Метод пузырька с флажком

from prettytable import PrettyTable
import time
import random

#метод пузырька с флажком
def bubble_method(arr):
    n=len(arr)
    for i in range(n-1):
        flag=True
        for j in range(n-1-i):
		    
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                flag = False
            if flag:
                break
    return arr

#Упорядоченный массив
def count1(arr):
    temp_arr = arr.copy()
    t0 = time.time()
    bubble_method(temp_arr)
    return round((time.time() - t0) * 1000, 6)

#Случайный массив
def count2(arr):
    temp_arr = arr.copy()
    random.shuffle(temp_arr)
    t0 = time.time()
    bubble_method(temp_arr)
    return round((time.time() - t0) * 1000, 6)

#Обратно упорядоченный массив
def count3(arr):
    temp_arr = sorted(arr)
    temp_arr.reverse()
    t0 = time.time()
    bubble_method(temp_arr)
    return round((time.time() - t0) * 1000, 6)


n_1 = int(input('Введите N_1 :'))
n_2 = int(input('Введите N_2 :'))
n_3 = int(input('Введите N_3 :'))

arr1 = [i for i in range(n_1)]
arr2 = [i for i in range(n_2)]
arr3 = [i for i in range(n_2)]

print()
print('Calculate time (milisec.)')
print('Метод пузырька с флажком')
myTable = PrettyTable(["Тип","N_1", "N_2", "N_3"])

myTable.add_row(["Упорядоченный массив", count1(arr1), count1(arr2), count1(arr3)])

myTable.add_row(["Случайный массив", count2(arr1), count2(arr2), count2(arr3)])

myTable.add_row(["Обратно упорядоченный массив", count3(arr1), count3(arr2), count3(arr3)])

print(myTable)

#Метод sorted()
#Упорядоченный массив
def count4(arr):
    temp_arr = arr.copy()
    t0 = time.time()
    sorted(temp_arr)
    return round((time.time() - t0) * 1000, 6)

#Случайный массив
def count5(arr):
    temp_arr = arr.copy()
    random.shuffle(temp_arr)
    t0 = time.time()
    sorted(temp_arr)
    return round((time.time() - t0) * 1000, 6)

#Обратно упорядоченный массив
def count6(arr):
    temp_arr = sorted(arr)
    temp_arr.reverse()
    t0 = time.time()
    sorted(temp_arr)
    return round((time.time() - t0) * 1000, 6)

print()
print('Calculate time (milisec.)')
print('Метод sorted()')
sofTable = PrettyTable(["Тип","N_1", "N_2", "N_3"])
sofTable.add_row(["Упорядоченный массив", count4(arr1), count4(arr2), count4(arr3)])
sofTable.add_row(["Случайный массив", count5(arr1), count5(arr2), count5(arr3)])
sofTable.add_row(["Обратно упорядоченный массив", count5(arr1), count5(arr2), count5(arr3)])

print(sofTable)