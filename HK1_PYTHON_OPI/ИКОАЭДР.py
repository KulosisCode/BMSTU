#      ИКОСАЭДР
from math import sqrt
a = 0
#input Длина ребра (a>0)
while a <= 0 :                                       
    a = float(input("Длинна ребра: "))
x = sqrt(5)
n = sqrt(3)
#Объём
V =  a**3*5*(x+3)/12
V = round(V,3)
print("Объём : ", V)

#Площадь поверхности
S =  a*a*5*n
S = round(S,3)
print("Площадь поверхности: ",S)

#радиус описанной сферы 
R1 = a*sqrt(10+2*x)/4
R1 = round(R1,3)
print("радиус описанной сферы: ",R1)

#радиус вписанной сфери 
R2 = a*n*(3+x)/12
R2 = round(R2,3)
print("радиус вписанной сфери: ",R2)
