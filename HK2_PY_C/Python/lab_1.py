#Чыонг Ван Хао   - ИУ7и-21Б
#Lab_1 - Метод половинного деления 


from scipy import optimize
from math import *
from prettytable import PrettyTable

def func(x):
    return cos(x)


# Функция-Метод половинного деления 
def findok(x, y): 
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
    return (x+y)/2

# Вывод результат(Метод половинного деления)
def method1(a, b, eps, h, turn):
    myTable = PrettyTable(["Нормер", "Отрезок", "Значение корня",
                             "Значение функции", "Код ошибки"])  
    num = 0
    st = a
    en = a + h
    codz = ''
    space = ''
    max_n = 0
    while (b-en) >= eps or max_n == 0 :
        if en >= b :
            en = b
            max_n += 1
        x = findok(st, en)
        if x != st - 1:  
            num += 1
            if fabs(func(x)) < eps :
                codz = '0'
                value = round(fabs(func(x)), 6)
                x_1 = str(round(x,6))
            else : 
                codz = '1'
                value = '-'
                x_1 = '-'
            space = str(round(st,6)) + ' .. ' + str(round(en,6)) 
            myTable.add_row([str(num),space, str(x_1), str(value),codz])      
        st = en
        en += h    
    if num == 0:
        myTable.add_row(["Данный метод не нашел корни на отрезке!",'-','-','-','-'])
    print(myTable)

# Метод bisect()
def method_bicsect(a, b, eps, h, turn):
    biTable = PrettyTable(["Нормер", "Отрезок", "Значение корня",
                             "Значение функции", "Код ошибки"])  
    st = a
    en = a + h
    num = 0
    codz = '0'
    max_n = 0
    while (b-en) >= eps or max_n == 0:
        if en >= b : 
            en = b
            max_n += 1
        if func(st)*func(en) < 0 :
            num += 1
            x = optimize.bisect(func,st,en)
            space = str(round(st,6)) + ' .. ' + str(round(en,6)) 
            value = str(fabs(round(func(x), 6)))
            x_1 = str(round(x,6))
            biTable.add_row([str(num),space, x_1, value,codz])      
        st = en
        en += h
    if num == 0:
        biTable.add_row(["Данный метод не нашел корни на отрезке!",'-','-','-','-'])
    print(biTable)



#Ввод значение
print('Введите левый и правый корнцы интервал :')
a,b = map(float, input().split())
while b < a :
    print('Введите левый и правый корнцы интервал :')
    a,b = map(float, input().split())
eps = float(input('Введите Точность :'))
h = float(input('Введите шаг :'))
turn = int(input('Масксимльное количество интерции :'))    

#main
print()
print('0-нет ошибки')
print('1-Мало инерции')
print()
print('Метод половинного деления\n')
method1(a, b, eps, h, turn)
print()
print('Метод bisect()\n')
method_bicsect(a, b, eps, h, turn)