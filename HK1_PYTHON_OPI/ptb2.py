from math import sqrt

print("input a,b,c :")
a = float(input("input a:"))
b = float(input("input b:"))
c = float(input("input c:"))
if (a == 0):
    if (b == 0):
        if (c ==0):
            print("(X - любое)бесконечно много корней")
        else:
            print(" Нет решений ")
    else:
        print("x=",-c/b)
else :
    q = b*b-4*a*c
    f = 2*a
    if (q < 0):
        print("Нет Действительных корней ")
    elif q == 0 :
        x = -b/f
        print("x=",x)
    else:
        s_D = sqrt(q)
        x1 = float((-b + s_D)/f)
        print("x1= ",x1)
        x2 = float((-b - s_D)/f)
        print("x2= ",x2)
        
