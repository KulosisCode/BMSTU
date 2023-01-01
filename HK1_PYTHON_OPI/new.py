from math import *
x = float(input('input x: '))
E = float( input("input Eps: "))
S = x
now = 0
check = True
tu = 1.0
mau = 1.0
i = 0
while check :
    i += 2
    tu = tu * (i-1)
    mau = mau * i
    now = x**( i-1 )*tu*mau/( i-1 )  
    print(now)
    if now > E :
        S += now
    else :
        check = False
print( 'Sum :{:10.4f}'.format(S),)

