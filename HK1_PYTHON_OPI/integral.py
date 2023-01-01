'''
Название лабораторной работы:
    "Интегралы"
    
Назначение лабораторной работы:
    Вычислить значения различными методами(Буль и левые прямоугольники)

Переменные и их обозначения:
    summ = сумма
    square = квадрат числа
    left_rect = левые прямоугольники
    boole = метод Буля
    a,b = границы
    n1,n2 = количество разбиений
'''
from scipy import integrate
from math import fabs


def func(x):
    return x * x


def left_rect(a, b, n, fn):
    h = (b - a) / n
    summ = 0
    for i in range(n):
        summ += fn(a + h * i)
    summ *= h
    return summ


def boole(a, b, n, fn):
    h = (b - a) / n
    summ = 0
    for i in range(1, n // 4 + 1):
        summ += (7 * fn(a + h * (4 * i - 4)) +
                 32 * fn(a + h * (4 * i - 3)) +
                 12 * fn(a + h * (4 * i - 2)) +
                 32 * fn(a + h * (4 * i - 1)) +
                 7 * fn(a + h * 4 * i))
    summ *= 2 * h / 45
    return summ


print()
a = float(input('Введите левую границу a: '))
b = float(input('Введите правую границу b: '))
print('Введите ниже количества разбиений n, учитывайте, что метод \
Буля работает только для n кратных 4')
n1 = int(input('n1: '))
while n1 % 4 != 0:
    print('Неверное число рабиений')
    n1 = int(input('n1: '))
n2 = int(input('n2: '))
while n2 % 4 != 0:
    print('Неверное число разбиений')
    n2 = int(input('n2: '))
print()
print('{:^30s}'.format('Метод'), chr(9474), 
      '{:^15s}'.format('n = ' + str(n1)), chr(9474),
      '{:^15s}'.format('n = ' + str(n2)))
print('{:^30s}'.format('Метод левых прямоугольников'), chr(9474),
      '{:^15.9}'.format(left_rect(a, b, n1, func)),
      chr(9474), '{:^15.9}'.format(left_rect(a, b, n2, func)))
print('{:^30s}'.format('Метод Буля'), chr(9474),
      '{:^15.9}'.format(boole(a, b, n1, func)), chr(9474),
      '{:^15.9}'.format(boole(a, b, n2, func)))
print()


print()
eps = float(input('Введите точность эпсилон: '))
n = 1
h = (b - a) / n
bule = False
while fabs(left_rect(a, b, 2 * n, func) - left_rect(a, b, n, func)) > eps:
    if n % 4 == 0 and fabs(boole(a, b, 2 * n, func) - boole(a, b, n, func)) <= eps:
        bule = True
        break
    n *= 2

if bule:
    n = 1
    while fabs(left_rect(a, b, 2 * n, func) - left_rect(a, b, n, func)) > eps:
        n *= 2
    print('Табличное значение интеграла:',
          '{:^9.9f}'.format(integrate.quad(func, a, b)[0]))
    print('Используем метод левых прямоугольников')
    print('Вычисленное значение интеграла при количестве участков разбиения -',
          n * 2, ':', '{:^9.9}'.format(left_rect(a, b, n * 2, func)))
    abs_m = fabs(integrate.quad(func, a, b)[0] - left_rect(a, b, n * 2, func))
    print('Абсолютная ошибка:', '{:^9.9f}'.format(abs_m))
    print('Относительная ошибка:', '{:^9.9f}'.format(abs_m /
                                                integrate.quad(func, a, b)[0]))
else:
    n = 4
    while fabs(boole(a, b, 2 * n, func) - boole(a, b, n, func)) > eps:
        n *= 2
    print('Табличное значение интеграла:',
          '{:^9.9}'.format(integrate.quad(func, a, b)[0]))
    print('Используем метод Буля')
    print('Вычисленное значение интеграла при количестве участков разбиения -',
          n * 2, ':', '{:^9.9}'.format(boole(a, b, n * 2, func)))
    abs_m = fabs(integrate.quad(func, a, b)[0] - boole(a, b, n * 2, func))
    print('Абсолютная ошибка:', '{:^9.9f}'.format(abs_m))
    print('Относительная ошибка:', '{:^9.9f}'.format(abs_m /
                                                integrate.quad(func, a, b)[0]))
