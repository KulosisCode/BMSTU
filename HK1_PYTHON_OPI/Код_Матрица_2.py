from math import *
row = 0
col = 0
while (row <= 0) or (row > 7) :
    row = int(input('строка :'))
while (col <= 0) or (col >9) :
    col = int(input('столбец :'))
B= []
for i in range(0,row):
    B.append([])
    print('B[',i,'][] : ',end = '')
    B[i]=list(map(float,input().split()))
    print()
    
print('Матрица B начало:')
for i in range(0,row):
    for j in range(0,col):
        print('{:3.1f}'.format(B[i][j]),end='  ')
    print()

n = 0
A = []
for i in range(row) :
        for j in range(col):
            if B[i][j] < 0 :
                n += 1
                A.append(B[i][j]) 
                break

maxa = A[0]
indexa = 0
print('Массив A :')
for i in range(n) :
    print('{:4.1f}'.format(A[i]),end = ' ')
    if maxa < A[i]:
        maxa = A[i]
        indexa = i

print()
print('максимального Элемента : ',A[indexa])
print('индекс максимального Элемента :', indexa)

print('Матрица B после  :')
for i in range(0,row):
    for j in range(0,col):
        print('{:4.1f}'.format(B[i][j] + indexa),end='  ')
    print()



        
