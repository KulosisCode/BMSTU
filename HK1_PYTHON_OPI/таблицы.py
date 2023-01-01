#Опратор (for)

from math import cos, pi
r = -1
num = 0
numf1 = 0
print('-------------------------------------------------------------------------')
print('|\tНомер\t|\tАргумент\t|\tf1\t|\tf2\t|')
print('-------------------------------------------------------------------------')
for r in range(-10,10 + 1,1) :
    r /= 10
    num += 1 
    f1 = r**2 - (cos( pi * r)) ** 2
    if (f1 >= -0.5) and (f1 <= 0.5):
        numf1 += 1
    f2 = r**3 - 4*r**2 + 2
    print('|\t{}\t|\t{:1.1f}\t\t|\t{:5.2f}\t|\t{:5.2f}\t|'.format(num,r,f1,f2))
    r += 0.1
print('-------------------------------------------------------------------------')
print('Каличество Значений f1, попавших в диапозон -0.5 <= f1 <= 0.5 :',numf1)