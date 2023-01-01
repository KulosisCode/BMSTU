from scipy import optimize
from math import *
from prettytable import PrettyTable

def func(x):
    return cos(x)

def ini():
    mytable = PrettyTable(["Нормер", "Отрезок", "Значение корня", "Значение функции", "Код ошибки")     
    




#функций вывод таблицы
# def printtext(num,st,en,x,space,eps,codz) :
#     print(chr(9472)*74)
#     print('|  {:^3d}   |'.format(num),end = '')
#     if st > 0 and en > 0 : space = ' '*2
#     elif st < 0 and en < 0 : space = '' 
#     print(' {:^3.1f} до {:^3.1f} '.format(st,en),space,end = '')
#     print('|   {:^10.5f}  '.format(x),end = '')
#     print('|   {:^10.5f}    '.format(func(x)),end  = '')  
#     print(codz) 

#Метод половинного деления
def findok(x, y):
    global bug 
    check = False
    if abs(func(x)) < eps:
        return x
    if abs(func(y)) < eps:
        return y
    if func(x)*func(y) < 0 :
        check = True
    if check == False:
        return x-1
    n = 1
    while (y - x) > eps and n <= turn :
        if func((x+y)/2)*func(x) < 0 :
            y = (x+y)/2
        else :
            x = (x+y)/2
        n += 1
    if y - x > eps : bug = False
    return (x+y)/2

#Ввод
print('Введите левый и правый корнцы интервал :')
a,b = map(float, input().split())
eps = float(input('Введите Точность :'))
h = float(input('Введите шаг :'))
turn = int(input('Масксимльное количество интерции :'))


# print()
# print('Метод половинного деления')
# print(chr(9472)*74)
# print('| Нормер |    Отрезок   ',end ='')
# print( '| Значение корня | Значение функции | Код ошибки |')
st = a
en = a + h
num = 1
bug = True
while (b-en) >= eps:
    bug = True
    x = findok(st, en)
    if x != st - 1:
        space = ' '
        if bug : codz = '|      -      |'
        else : codz = '|низ. итерации|'
        printtext(num,st,en,x,space,eps,codz)
        num += 1
    st = en
    en += h
print()

# #Метод bisect()
# print()
# print('Метод bisect()')
# print('Метод половинного деления')
# print(chr(9472)*74)
# print('| Нормер |    Отрезок   ',end ='')
# print( '| Значение корня | Значение функции | Код ошибки |')
st = a
en = a + h
num = 1
codz = '|      -      |'
while (b-en) >= eps:
    if func(st)*func(en) < 0 :
        space = ' '
        x = optimize.bisect(func,st,en)
        printtext(num,st,en,x,space,eps,codz)
        num += 1
    st = en
    en += h
