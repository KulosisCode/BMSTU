# Чыонг Ван Хао
# ИУ7И-11Б
# Шифрование- лаб_9
'''
Программа позволит с использованием меню:
0. Завершить программу
1. Ввод строки.
2. Настройка шифрующего алгоритма.
3. Шифрование строки, используя шифр Виженера.
4. Расшифровывание строки
'''
# f1 = кодовый номер первой буквы алфавита
# s_f = количество букв

from math import *
#Menu tab
def menu() :
    print( 
        '''\
        1. Ввод строки.
        2. Настройка шифрующего алгоритма.
        3. Шифрование строки, используя шифр Виженера.
        4. Расшифровывание строки
        0. Завершить программу
        '''
        )
#encrypt function
def encrypt(s,key,f1,s_f) :
    en_s =[]
    space = 0
    for i in range(len(s)):
        if s[i] != ' ' :
            en_s.append(chr((ord(s[i]) - f1 + ord(key[i%len(key)-space])-f1)%s_f + f1))
        else :
            space += 1
            en_s.append(' ')
    return(en_s)

#decrypt function
def decrypt(s,key,f1,s_f) :
    de_s = []
    space = 0
    for i in range(len(s)) :
        if s[i] != ' ' :
            de_s.append(chr((ord(s[i]) - f1 - ord(key[i%len(key)-space])+f1 + s_f)%s_f + f1))
        else :
            space += 1
            de_s.append(' ')    
    return(de_s)    

while 1  :
    menu()
    select = -1
    while (select < 0) or (select > 4) :
        select = int(input())

    if select == 1 :
        #input string
        s = str(input('Введите строки : '))
        while len(s) == 0 :
            s = str(input('Введите строки : '))
        s = s.upper()

    elif select == 2 :
        #input key
        key = str(input('Введите key : '))
        while len(key) == 0 :
            key = str(input('Введите key : '))
        key = key.upper()
        if ord(key[0]) > 1000 :
            f1 = 1040   
            s_f = 32
        else :
            f1 = 65
            s_f =26

    elif select == 3 :
        #encrypt
        s = encrypt(s,key,f1,s_f)
        print('Шифрование строки : ',end='')
        for i in range(len(s)):
            print(s[i],end='')
        print() 

    elif select == 4 :
        #decrypt
        s =(decrypt(s,key,f1,s_f))
        print('Расшифровывание строки : ',end='')
        for i in range(len(s)):
            print(s[i],end='')
        print()

    else :
        break

    
    


   

    
