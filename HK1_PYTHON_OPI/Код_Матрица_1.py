from math import*

e = float(input('Точность : '))
a = float(input('a : '))
row = 0
col = 0
while (row <= 0) or (row > 15) :
    row = int(input('строка :'))
while (col <= 0) or (col >10) :
    col = int(input('столбец :'))

sum = 0

check = True
n = 0
while check :
    fc = 2*n+1
    t_1 = a**(fc)
    t_2 = 1
    for i in range(1,fc+1):
        t_2 *= i
    t = t_1/t_2
    if t <= e :
        check = False
    else :
        n += 1
        sum += t

Z = []

for i in range(0,row):
    Z.append([])
    print('Z[',i,'][] : ',end = '')
    Z[i] = list(map(float,input().split()))
    print()
print('sum :{:3.2f}'.format(sum))
print('Матрица Z :')
for i in range(0,row):
    for j in range(0,col):
        print('{:4.1f}'.format(Z[i][j]),sep=' ',end=' ')
    print()

n = 0
X = []
for i in range(0,row) :
    for j in range(0,col) :
        if (Z[i][j] > sum) :
            n += 1
            X.append(Z[i][j])
print('Количество элементов X :',n)    
if n > 0 :
    print("Вектор X :")
    for i in range(n):
        print(X[i],end =' ')
    print()
indexx = 0
if n > 1:
    maxx = X[0]
    for i in range(n):
       if X[i] > maxx :
        maxx = X[i]
        indexx = i
    X[0],X[indexx] = X[indexx],X[0]
  
if n > 0 :
    print("Вектор X после изменения:")
    for i in range(n):
        print(X[i],end =' ')
        

