''''
Чыонг Ван Хао  -  ИУ7И-11б
Интеграл
метод трапеций и метод Уэдла

Переменные и их обозначения:
    I = сумма(интеграл)    
    a,b = границы
    trape = Метод трапеций 
    wedd =  Метод Уэдла
    n1,n2 = количество разбиений
''' 
from math import *
# функции : x/(x+1)

def func(x):
    return (x/(x+1))

#точно значение итеграла

def real(x):
    return (1+x-log(1+x))

def trape(a,b,n,F):
    h = abs((b-a)/n)
    I = 0
    for i  in range(1,n):
        I += F(a + i*h)
    I += (F(a)+F(b))/2
    I *= h
    return(I) 

def wedd(a,b,n,F) :
    h = abs((b-a)/n)  
    I = 0
    for i in range(0,n,6) :
        I += (F(a+i*h) + 5*F(a+(i+1)*h) +
            F(a+(i+2)*h) + 6*F(a+(i+3)*h) +
            F(a+(i+4)*h) +5*F(a+(i+5)*h) + 
            F(a+(i+6)*h))
    I *= 3*h/10
    return(I)
       
a = float(input('Введите левую границу a: '))
b = float(input('Введите правую границу b: '))

print('Введите ниже количества разбиений n, учитывайте, что метод \
Уэдла работает только для n кратных 6')

n1 = int(input('n1: '))
while n1 % 6 != 0:
    print('Неверное число рабиений')
    n1 = int(input('n1: '))
n2 = int(input('n2: '))
while n2 % 6 != 0:
    print('Неверное число разбиений')
    n2 = int(input('n2: '))

print()
print('{:^30s}'.format('Метод'), chr(9474), 
      '{:^15s}'.format('n = ' + str(n1)), chr(9474),
      '{:^15s}'.format('n = ' + str(n2)))
print('{:^30s}'.format('Метод трапеций'), chr(9474),
      '{:^15.9}'.format(trape(a, b, n1, func)),
      chr(9474), '{:^15.9}'.format(trape(a, b, n2, func)))
print('{:^30s}'.format('Метод Уэдла'), chr(9474),
      '{:^15.9}'.format(wedd(a, b, n1, func)), chr(9474),
      '{:^15.9}'.format(wedd(a, b, n2, func)))
print()


I = real(b) - real(a)
print('точное значение итеграла {:^9.9}'.format(I))

eps = float(input('Точность :'))

print('Метод транций :')
n = 2
while (trape(a,b,2*n,func)-trape(a,b,n,func)) >= eps :
   print('n =',n,'{:^15.9}'.format(trape(a,b,n,func)))
   print('Абсолютная погрешность: {:^15.9} '.format(abs(I-trape(a,b,n,func))))
   print('Относительная погрешность: {:^15.9}'.format(abs((I-trape(a,b,n,func))/I)))
   n *= 2
print()

print('Метод Уэдла :')
n = 6
while (n%6 == 0) and (wedd(a,b,2*n,func)-wedd(a,b,n,func)) >= eps :
    print('n =',n,'{:^15.9}'.format(wedd(a,b,n,func)))
    print('Абсолютная погрешность: {:^15.9} '.format(abs(I-wedd(a,b,n,func))))
    print('Относительная погрешность: {:^15.9}'.format(abs((I-wedd(a,b,n,func))/I)))
    n *= 2
