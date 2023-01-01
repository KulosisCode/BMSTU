
#Опратор (for)
#Таблица

from math import *
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
    
num = 0
numf1 = 0

print('-------------------------------------------------------------------------')
print('|\tНомер\t|\tАргумент\t|\tf1\t|\tf2\t|')
print('-------------------------------------------------------------------------')
for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
    r = round(r/10**3,2)
    num += 1 
    f1 = r**2 - (cos( pi * r)) ** 2
    if (f1 >= -0.5) and (f1 <= 0.5):
        numf1 += 1
    f2 = r**3 - 4*r**2 + 2
    print('|\t{}\t|\t{:1.1f}\t\t|\t{:5.2f}\t|\t{:5.2f}\t|'.format(num,r,f1,f2))    
print('-------------------------------------------------------------------------')
print('Каличество Значений f1, попавших в диапозон -0.5 <= f1 <= 0.5 :',numf1)


#Определить также разность между максимальным и минимальным значением С

#s-Общее значение функции C от  r = -1 до r = 1
#i-Бегущая переменная
#a-Переменная
#c-Функция c = r**3 - 4*r**2 + 2
#maxc,minc-Максимальное и минимальное значение С

#График



j = int(input("Введите количество засечек j (от 4 до 8): "))
while ((j<4) or (j>8)):
    print("J должен быть от 4 до 8")
    j = int(input("Введите количество засечек j снова: "))
print("\n")

s = 0
for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
    r = round(r/10**3,2)
    c = r**3 - 4*r**2 + 2
    s += c
maxc = minc = round(s/((n-m)/i+1),2)
for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
    r = round(r/10**3,2)
    c = r**3 - 4*r**2 + 2
    if c > maxc: maxc=round(c,2)
    if c < minc: minc=round(c,2)
d = (maxc-minc)/(j-1)

print(" "*8,end="")
for k in range(0,j):
    l = minc + k*d
    if (abs(l) <= 10**2):
            print("{:3.1f}".format(l)," "*6,end=" ")
    else: print("{:4.1f}".format(l)," "*5,end=" ")
print()

print("   x "+" "*6,end="")
for k in range(0,j-1):
    print(chr(9524)+chr(9472)*11,end="")
print(chr(9524))
print()

vtymax = 11*(j-1)
x0 = (-minc)/(maxc-minc)
vt0 = round(x0*(vtymax))
if vt0 == 0: vt0 += 1
do = (maxc-minc)/(11*(j-1)) 
if (minc > 0) or (maxc < 0):
    for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
        r = round(r/10**3,2)
        c = r**3 - 4*r**2 + 2
        x =(c-minc)/(maxc-minc)
        vty = int(x*(vtymax))
        print("{:6.2f}".format(r)+7*" "+vty*" "+"*")
else:
    for r in range(round(m*10**3),round(n*10**3+1),round(i*10**3)):
        r = round(r/10**3,2)
        c = r**3 - 4*r**2 + 2
        x = (c-minc)/(maxc-minc)
        vty = round(x*(vtymax))
        if (c<0):
            if (-c)<do:
                print("{:6.2f}".format(r)+5*" "+(vt0)*" "+"*")
            else:
                print("{:6.2f}".format(r)+5*" "+vty*" "+"*"+(vt0-vty-1)*" "+(chr(9474)))
        if (c==0):
            print("{:6.2f}".format(r)+5*" "+vty*" "+("*"))
        if (c>0):
            if (c<do):
                print("{:6.2f}".format(r)+5*" "+vt0*" "+"*")
            else:
                print("{:6.2f}".format(r)+5*" "+vt0*" "+(chr(9474))+(vty-vt0-1)*" "+"*")

