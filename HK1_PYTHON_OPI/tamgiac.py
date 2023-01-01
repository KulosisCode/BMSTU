#Определение длин строн треугольника по заданным координатам точек (тип Interger)
#Найти также медиану, проведённую из наибольшего угла треугольника.
#При вычислении длин сторон под корнем должно быть только целое выражение. 
#Никаких операций над действительными числами, никаких преобразований типов ит.д.
#Определить является ли треугольник равнобедркенным.
#Даллее ввести координаты одной точки(тоже Integer) и опредедить, находится ли она внутри треугольника или нет
#Если находится, ио найти расстояние от этой точки до наиболее удалённой строны или её продолжения.

from math import *

eps = 1e-6

a = list(map(int,input("координат a :").split()))
b = list(map(int,input("координат b :").split()))
c = list(map(int,input("координат c :").split()))

ab = [(b[0] - a[0]),(b[1] - a[1])]
bc = [(c[0] - b[0]),(c[1] - b[1])]
ac = [(c[0] - a[0]),(c[1] - a[1])]

#Длин сторон
Lab = sqrt(ab[0]**2 + ab[1]**2 )
print("Длина AB: {:7.2f}".format(Lab))
Lbc = sqrt(bc[0]**2 + bc[1]**2 )
print("Длина BC: {:7.2f}".format(Lbc))
Lac = sqrt(ac[0]**2 + ac[1]**2 )
print("Длина AC: {:7.2f}".format(Lac))

if (Lab + Lac <= Lbc) or (Lab + Lbc <= Lac) or(Lbc + Lac <= Lab) :
    print("нет треугольник")
else :

    # Координат Медианы 
    gtmax =max(Lab,Lbc,Lac)
    if fabs(gtmax - Lab) < eps :
        M = [(a[0] + b[0])/2,(a[1] + b[1])/2]
        TT = [M[0] - c[0],M[1] - c[1]] 
        print("Медиана CM: ",TT," точка начало: ",c, " точка конец:",M, )
    elif fabs(gtmax - Lbc) < eps :
        M = [(b[0] + c[0])/2,(b[1] + c[1])/2 ]
        TT = [M[0] - a[0],M[1] - a[1]]
        print("Медиана AM: ",TT," точка начало: ",a, " точка конец:",M)
    else   : 
        M = [(a[0] + c[0])/2,(a[1] + c[1]/2)]
        TT = [M[0] - b[0],M[1] - b[1]]
        print("Медиана BM: ",TT," точка начало: ",b, " точка конец:",M)
    D_M = sqrt (TT[0]**2 +TT[1]**2)
    print("длина Медианы : {:7.2f}".format(D_M))

    #треугольник равнобедренным
    if Lab == Lbc :
        print("треугольник равнобедренным на В ")
    elif Lab == Lac :
        print("треугольник равнобедренным на A ")
    elif Lac == Lbc :
        print("треугольник равнобедренным на C ")
    else :
        print("треугольник неравнобедренным ")

    check = True
    
    # ввода любая точка
    P = list(map(int,input("координат P: ").split()))

    # f = a(x-x1) + b(y-y1) : линейные уравнения

    # AB
    Fp = ab[1]*(P[0]-a[0]) - ab[0]*(P[1]-a[1])
    Fc = ab[1]*(c[0]-a[0]) - ab[0]*(c[1]-a[1])
    if Fp*Fc <0 :
        check = False

    #BC
    Fp = bc[1]*(P[0]-b[0]) - bc[0]*(P[1]-b[1])
    Fa = bc[1]*(a[0]-b[0]) - bc[0]*(a[1]-b[1])
    if Fp*Fa <0 :
        check = False

    #AC
    Fp = ac[1]*(P[0]-a[0]) - ac[0]*(P[1]-a[1])
    Fb = ac[1]*(b[0]-a[0]) - ac[0]*(b[1]-a[1])
    if Fp*Fb <0 :
        check = False

    if check == True :
        print("P находится внутри треугольник!")
    else :
        print("P не находится внутри треугольник!")


    #найти расстояние от точка P до наиболее удалённой строны или её продолжения

    if check == True :
        Dp_ac = abs(ac[1]*(P[0]-a[0]) - ac[0]*(P[1]-a[1]))/ sqrt(ac[0]**2+ac[1]**2)
        Dp_ab = abs(ab[1]*(P[0]-a[0]) - ab[0]*(P[1]-a[1]))/ sqrt(ab[0]**2+ab[1]**2)
        Dp_bc = abs(bc[1]*(P[0]-b[0]) - bc[0]*(P[1]-b[1]))/ sqrt(bc[0]**2+bc[1]**2)

        Dpmax= max(Dp_ac, Dp_ab, Dp_bc)

        if Dp_ac == Dpmax :
            print("расстояние от P до наиболее удалённой стороны AC: {:7.2f} ".format(Dp_ac))
        elif Dp_ab == Dpmax :
            print("расстояние от P до наиболее удалённой стороны AB: {:7.2f} ".format(Dp_ab))
        else :
            print("расстояние от P до наиболее удалённой стороны BC: {:7.2f} ".format(Dp_bc))


