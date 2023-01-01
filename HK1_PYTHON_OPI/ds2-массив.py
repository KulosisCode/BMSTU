#самый большой и самый маленький элемент
#Рассмотрим, симметричен ли массив,
#в противном случае отсортируйте массив в порядке возрастания

from math import *
n = int(input('количество элементов n :'))
if n <= 0 :
    n = int(input('количество элементов n :'))
A = [0]*n
for i in range(n) :
    print('A[',i,']= ',end='')
    A[i] = int(input())
print('массив : ',end = '')
for i in range(n):
    print(A[i],end = ' ')
print()
max = A[0]
min = A[0]
for i in range(n) :
    if max < A[i] : 
        max = A[i]
    if min > A[i] :
        min = A[i]
print('самый большой элемент :',)
for i in range(n) :
    if A[i] == max :
        print('Число',max,' -- index :',i) 

print('самый маленький элемент :',)
for i in range(n) :
    if A[i] == min :
        print('Число',min,' -- index :',i ) 

check = True
for i in range(n) :
    if A[i] != A[n-i-1] :
        check = False
    if check == False :
        break
if check == True :  
    print('массив симметричен!')
else :
    print('массив не симметричен!')
    for i in range(n-1) :
        for j in range(i+1,n) :
            if A[i] > A[j]:
                t = A[i]
                A[i] = A[j]
                A[j] = t
    print('серийный номер после сортировки :')
    for i in range(n):
        print(A[i],end = ' ')
   
