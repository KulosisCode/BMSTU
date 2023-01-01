# находит элемент в массиве с наибольшим количеством делителей
# положительные целые числа
# сколько простых чисел в массив
from math import *
n = int(input('количество элементов n :'))
if n <= 0 :
    n = int(input('количество элементов n :'))
A = [0]*n
for i in range(n) :
    print('A[',i,']= ',end='')
    A[i] = int(input())
    if A[i] <= 0 :
        print('A[',i,']= ',end='')
        A[i] = int(input())   
    
print('массив : ',end = '')
for i in range(n):
    print(A[i],end = ' ')
print()

max = 0
for i in range(n):
    num = 0
    for j in range(1,A[i]+1) :
        if A[i] % j == 0 :
            num += 1
        if max < num :
            max = num

print('находит элемент в массиве с наибольшим количеством делителей:')

for i in range(n):
    num = 0
    for j in range(1,A[i]+1) :
        if A[i] % j == 0 :
            num += 1
        if num == max :
            print('Число:',A[i],'--index: ',i,'--количество делители :',num,sep=' ')
            print('\t делители:',end=' ')
            for k in range(1,A[i]+1):
                if A[i] % k == 0 :
                    print(k,end=' ')   
            print()
num1 =0
for i in range(n):
    num = 0
    for j in range(1,A[i]+1) :
        if A[i] % j == 0 :
            num += 1                             
    if num == 2 :
        num1 += 1
print('сколько простых чисел: ',num1)
 
