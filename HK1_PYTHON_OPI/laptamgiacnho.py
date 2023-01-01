from math import *

eps = 1e-6
a = list(map(int,input("координат a :").split()))
b = list(map(int,input("координат b :").split()))
c = list(map(int,input("координат c :").split()))

ab = [(b[0] - a[0]),(b[1] - a[1])]
bc = [(c[0] - b[0]),(c[1] - b[1])]
ca = [(a[0] - c[0]),(a[1] - c[1])]


#Длин сторон
Lab = sqrt(ab[0]**2 + ab[1]**2 )
print("Длина AB: {:7.2f}".format(Lab))
Lbc = sqrt(bc[0]**2 + bc[1]**2 )
print("Длина BC: {:7.2f}".format(Lbc))
Lca = sqrt(ca[0]**2 + ca[1]**2 )
print("Длина AC: {:7.2f}".format(Lca))
if (Lab + Lca <= Lbc) or (Lab + Lbc <= Lca) or(Lbc + Lca <= Lab) :
    print("нет треугольник")
else :
    # Найти Медиану  
        gtmin =min(Lab,Lbc,Lca)
        if fabs(gtmin - Lab) < eps :
            M = [(a[0] + b[0])/2,(a[1] + b[1])/2]
            TT = [M[0] - c[0],M[1] - c[1]] 
            print("Медиана CM: ",TT," точка начало: ",c,  " точка конец:",M)
        elif fabs(gtmin - Lbc) < eps :
            M = [(b[0] + c[0])/2,(b[1] + c[1])/2 ]
            TT = [M[0] - a[0],M[1] - a[1]]
            print("Медиана AM: ",TT," точка начало: ",a, " точка конец:",M)
        else   : 
            M = [(a[0] + c[0])/2,(a[1] + c[1])/2]
            TT = [M[0] - b[0],M[1] - b[1]]
            print("Медиана BM: ",TT," точка начало: ",b, " точка конец:",M)
        LM = sqrt (TT[0]**2 +TT[1]**2)
        print("длина Медианы : {:7.2f}".format(LM))
