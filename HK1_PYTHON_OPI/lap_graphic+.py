#Опратор (for)

from math import *

num = 0


m = float(input("Введите начальное значение M: "))
while ((m < -1000) or (m > 1000)):
    print("M должно быть в [-1000,1000]")
    m = int(input("Введите начальное значение M снова: "))
n = float(input("Введите конечное значение N: "))
while ((n > 1000) or (n <= m)):
    print("N должно быть больше M и в (-1000,1000]")
    n = int(input("Введите конечное значение N снова: "))
i = float(input("Введите диапазон изменения переменной i: "))
while (i>(n-m)):
    print("I должен быть меньше или равен (N-M)")
    i = float(input("Введите диапазон изменения переменной i снова: "))

print('---------------------------------------------------------')
print('|\tНомер\t|\tАргумент\t|\ty\t|')
print('---------------------------------------------------------')
x = m
while x <= n :
    
    num += 1 
    y = cos(x)

    print('|\t{}\t|\t{:1.1f}\t\t|\t{:5.2f}\t|'.format(num,x,y))
    x += i
print('----------------------------------------------------------')





j = int(input("Введите количество засечек j (от 4 до 8): "))
while ((j<4) or (j>8)):
    print("J должен быть от 4 до 8")
    j = int(input("Введите количество засечек j снова: "))
print("\n")
s = 0

maxc = 1
minc = -1
d = (maxc-minc)/(j-1)
print(" "*10,end="")
for k in range(0,j):
    l = minc + k*d
    print("{:5.2f}".format(l)," "*14,end=" ")
    
print()
print("     x "+" "*8,end="")
for k in range(0,j):
    print(chr(9524)+chr(9472)*20,end="")
    
print()

vtymax = round(21*(j-1))
x0 = (-minc)/(maxc-minc)
vt0 = round(x0*(vtymax))
if vt0 == 0: vt0 += 1
do = (maxc-minc)/(21*(j-1))
if (minc > 0) or (maxc < 0):
    for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
        r = round(r/10**3,2)
        c = cos(r)
        x =(c-minc)/(maxc-minc)
        vty = int(x*(vtymax))
        print("{:8.2f}".format(r)+7*" "+vty*" "+"*")
else:
    for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
        r = round(r/10**3,2)
        c = cos(r)
        x = (c-minc)/(maxc-minc)
        vty = round(x*(vtymax))
        if (c<0):
            if (-c)<do:
                print("{:8.2f}".format(r)+7*" "+(vt0)*" "+"*")
            else:
                print("{:8.2f}".format(r)+7*" "+vty*" "+"*"+(vt0-vty-1)*" "+(chr(9474)))
        if (c==0):
            print("{:8.2f}".format(r)+7*" "+vty*" "+("*"))
        if (c>0):
            if (c<do):
                print("{:8.2f}".format(r)+7*" "+vt0*" "+"*")
            else:
                print("{:8.2f}".format(r)+7*" "+vt0*" "+(chr(9474))+(vty-vt0-1)*" "+"*")

