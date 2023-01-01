from math import *

E = float(input("точность :"))

s = 0
sh = 0

check = True
i = 0

while check :
    i += 1
    sh = (-1) ** (i - 1) /( 2*i -1 )
    if abs(sh) > E :
        s += sh
#        print('n = ',i,'value :',sh)
    else :
        check = False
s *= 4
print('Sum :{:7.2f}'.format(s),' с точностью :',E)
print('i :',i)


