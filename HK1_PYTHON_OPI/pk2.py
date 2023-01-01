
from math import *

def fun(A,row,col ) : 
    B=[]
    for i in range(row) :
        for j in range(col):
            check = True
            for k in range(len(B)) :
                if A[i][j] == B[k] : 
                    check = False       
            if check :
                B.append(A[i][j])
    print('количество различных символов : ',len(B))
    for k in range(len(B)):
        dem = 0 
        for i in range(row):
            for j in range(col):
                if B[k] == A[i][j]:
                    dem += 1
        print(B[k],'   частоту символа  :',dem)        




print('input')
row = int(input('количество строк :'))
while row <= 0 :
    row = int(input('количество строк :'))
col = int(input('количество столбцов :'))    
while (col == row) or (col <= 0):
    col = int(input('количество столбцов :'))

A = []
for i in range(row) :
    A.append([])
    print('строк ',i, ':',end=' ')
    A[i] = list(map(str,input().split()))
    print()

print('исходная матрица :')   
for i in range (row):
    for j in range(col):
        print(A[i][j],end = ' ')
    print()

fun(A,row,col)
print()

for i in range(row):
    for j in range(col) :
        if A[i][j].isdigit():
            A[i] = ['*']*col
            for k in range(row):
                if not A[k][j].isdigit():
                    A[k][j] = '*'


print('матрица преобразования')
for i in range (row):
    for j in range(col):   
        print(A[i][j],end =' ')
    print()
fun(A,row,col)
        
