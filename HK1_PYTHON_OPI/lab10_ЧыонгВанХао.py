# Чыонг Ван Хао
# ИУ7И-11Б
# лаб_10

#print menu
def menu():
    print('''\
        1. Выравнивание текста по левому краю.
        2. Выравнивание текста по правому краю.
        3. Выравнивание текста по ширине.
        4. Удаление заданного слова.
        5. Замена одного слова другим во всем тексте.
        6. Вычисление арифметического выражения.
        7. Определить сколько имеется слов из 2,3,4 букв в каждом предложении.
        0. Завершить программу
        '''
        )
#print text
def printtxt(text) :
    for ele in text :
        print(ele)
#Выравнивание текста по левому краю.
def alig_left(text):
    newtext = ['']*len(text)
    space = 1
    line = ''
    for i in range(len(text)):
        for ele in text[i] :
            if ele != ' ' :
                line += ele
                space = 0
            else :
                if space == 0 :
                    line += ele
                    space += 1
                else :
                    pass 
        newtext[i] = line
        line = ''    
    return(newtext)            

#Выравнивание текста по правому краю.
def alig_right(text):
    text = alig_left(text)
    maxline = 0
    newtext = ['']*len(text)
    for i in range(len(text)) :
        if len(text[i]) > maxline :
            maxline = len(text[i])
    for i in range(len(text)):
        newtext[i] = ' '*(maxline - len(text[i])) + text[i]
    return(newtext)

# Выравнивание текста по ширине.
def alig_width(text):
    text = alig_left(text)
    maxline  = 0
    newtext = ['']*len(text)
    for i in range(len(text)) :
        if len(text[i]) > maxline :
            maxline = len(text[i])
    for i in range(len(text)):
        newtext[i] = ' '*((maxline - len(text[i]))//2) + text[i]
    return(newtext)


# Удаление заданного слова.
def remove(text) :
    choice = input('Введите слово которое нужно удалить: ')
    choice = choice.upper()
    newtext = ['']*len(text)
    line = ''
    for i in range(len(text)):
        for el in text[i].split():
            element = el.upper()    
            if (element == choice or element == choice + ','
                    or element == choice + '.' or element == choice + '!'
                    or element == choice + '?'):
                if element != choice:
                    line += el[-1] + ' '
                else:
                    pass
            else:
                line += el + ' '
        newtext[i] = line
        line = ''
    return(newtext)

#Замена одного слова другим во всем тексте.
def replace(text) :
    while True:
        try:
            choice = input('Введите через пробел два слова:' +
                           ' сначала - то, что нужно заменить' + '\n').split()
            if len(choice) == 2:
                break
        except:
            print('Введите два слова через пробел!')
    st1 = choice[0].lower()
    newtext = ['']* len(text)
    line = ''
    for i in range(len(text)):
        for el in text[i].split():
            st2 = choice[1].lower()
            check = False
            if el[0].isupper() :
                check = True  
            element =  el.lower()   
            if (element == st1 or element == st1 + ','
                    or element == st1 + '.' or element == st1 + '!'
                    or element == st1 + '?'):
                if element != choice[0]:
                    line += st2 + element[-1] + ' '
                else:
                    if check :
                        line += st2[0].upper() + st2[1:] + ' '
                    else :
                        line += st2 + ' ' 
            else:
                line += el + ' '
        newtext[i] = line
        line = ''
    return(newtext)

#Вычисление арифметического выражения.
def calcu(text) :
    operations = ['+','-','*','/','**','//','(',')','%']
    cal_arr = []
    line = ''
    for i in range(len(text)):
        for el in text[i].split():
            for j in range(len(el)) :
                if el[j].isdigit() or el[j] in operations :
                    line += el[j]
        if line != '' :
            cal_arr.append(line) 
        line = ''   
    for i in range(len(cal_arr)):
        print(cal_arr[i],' = ',eval(cal_arr[i]))
    newtext = ['']*len(text)
    num = 0
    line = ''
    for i in range(len(text)) :
        for el in text[i].split():
            check = True
            for j in range(len(el)) :
                if el[j].isdigit() or el[j] in operations :   
                    check = False
                    break
            if not check :
                n = eval(cal_arr[num])
                line += str(n) +' '
                num += 1
            else :
                line += el +' '
        newtext[i] = line
        line = ''
    printtxt(newtext)  



# Определить сколько имеется слов из 2,3,4 букв в каждом предложении.
def countnum(text) :
    num = 1
    num2 = 0
    num3 = 0
    num4 = 0
    for i in range(len(text)):
        for el in text[i].split():
            n = len(el)
            if el[-1] == '.' or el[-1] == ',' or el[-1] == '!' or el[-1] == '?' :
                n -= 1
            if n == 2 :
                num2 += 1
            elif n == 3 :
                num3 += 1 
            elif n == 4 :
                num4 += 1 
            if el[-1] == '.'  or el[-1] == '!' or el[-1] == '?' :
                print('слов из 2,3,4 букв в предложении',num,' : ',num2,num3,num4,sep=' ')
                num += 1
                num2 = 0
                num3 = 0
                num4 = 0

        

text= [ 'They walked up the road together to the old man’s shack and went in through ',
        'its open door . The old man leaned the mast with its wrapped sail ',
        'against the wall. The boy put the box and the other gear ',
        'beside it. The mast was nearly as long as the one room of ',
        'the shack. The shack was made of the tough budshields of the ',
        'royal palm. On the brown walls of the flattened, there was ',
        'a picture.These were relics of his wife.',
        ]   

#main
while 1 :
    menu()
    select = -1
    while (select < 0) or (select > 7) :
        select = int(input('Введите номер команды : '))

    if select == 1 :
        text = alig_left(text)
        printtxt(text)
    elif select == 2 :
        text = alig_right(text)
        printtxt(text)
    elif select == 3 :
        text = alig_width(text) 
        printtxt(text)
    elif select == 4 :
        text = remove(text)
        printtxt(text)
    elif select == 5 :
        text = replace(text)
        printtxt(text)
    elif select == 6 :
        calcu(text)
    elif select == 7 :
        countnum(text)
    elif select == 0 :
        break

    
