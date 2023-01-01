from math import *

D = []
S = []
n = 0
while (n < 1) or ( n > 101) :
    n = int(input('Сколько Элементов :'))
    
for i in range(n):
    print('D[',i,']: ',end ='')
    D.append(float(input()))
print('Массив D :')
for i in range(n):
    print('{:3.1f}'.format(D[i]),end = ' ')
print()

num = 0
for i in range(n) :
    if D[i] < 0:
        num += 1
    if num == 3 :
        idexnum = i
        break
if num == 3 :
    D.remove(D[idexnum])
    for i in range(n-1):
        S.append(D[i])
    print('Массив S :')
    for i in range(n-1):
        print('{:3.1f}'.format(S[i]),end=' ')

else :
    print('Меньшие 3-x отрицательных элементов')

