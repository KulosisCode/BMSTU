

import pickle

def menu() :
    print('''\
        1. Создание БД.
        2. Добавление записи в БД.
        3. Вывод всей БД.
        4. Поиск записи по одному полю.
        5. Поиск записи по двум полям.
        0. Завершить программу 
        '''
        )
def createfile(filename) :  
    file_in = open('{}'.format(filename),'w')
    file_in.close()
base = {}
def writenew(filename) :
    global base
    file_in = open(filename,mode = 'rb')
    try :
        base = pickle.load(file_in)
    except EOFError :
        base = {}
    file_in.close()
    while True :
        name = input('Введите имя записи: ').strip()
        if name in base.keys():
            print('Это имя записи уже существовало.')
        else:
            base[name] = {}
            while True:
                field = input('Введите имя поля: ').strip()
                field_value = input('Введите значение поля: ').strip()
                base[name][field] = field_value
                i = input('Продолжить добавить поля? (1.Yes 2.No)').strip()
                if i == "2":
                    break
        i = input('Продолжить добавить записи? (1.Yes 2.No)').strip()
        if i == '2':
            break
    file_out = open(filename , mode = 'wb')
    pickle.dump(base, file_out)
    file_out.close()

def export(filename) :
    global base
    file_in = open(filename, mode = 'rb')
    base = pickle.load(file_in)
    print('|{:^19}|'.format('Записи'),end = '')
    fields = []
    for i in base.values():
        fields += list(i.keys())
    fields = list(set(fields))
    for i in fields:
        print('{:^20}|'.format(i),end = '')
    print('')
    print('-'*21*(len(fields) + 1))
    for i in base:
        print('|{:^19}|'.format(i), end = '')
        for j in fields:
            if j in base[i].keys():
                print('{:^20}|'.format(base[i][j]),end = '')
            else:
                print('{:^20}|'.format('x'), end = '')
        print('')
    file_in.close()     

def  findfield_1(filename):
    global base
    file_in = open(filename , mode = 'rb')
    base = pickle.load(file_in)
    find_field = input('Введите искомое поле: ').strip()
    find_value = input('Введите искомое значение: ').strip()
    answer = []
    for i in base:
        for j in base[i]:
            if j == find_field and base[i][j] == find_value:
                answer.append(i)
    if answer:
        print('Результат:', *answer , sep = '    ')
    else:
        print('Этого поля и значения нет.')
    file_in.close()

def findfield_2(filename):
    global base
    file_in = open(filename, mode = 'rb')
    base = pickle.load(file_in)
    find_field_01 = input('Введите первое искомое поле: ').strip()
    find_value_01 = input('Введите первое искомое значение: ').strip()
    find_field_02 = input('Введите второе искомое поле: ').strip()
    find_value_02 = input('Введите второе искомое значение: ').strip()
    answer = []
    for i in base:
        isExist01 = False
        isExist02 = False
        for j in base[i]:
            if j == find_field_01 and base[i][j] == find_value_01:
                isExist01 = True
            if j == find_field_02 and base[i][j] == find_value_02:
                isExist02 = True
        if isExist01 and isExist02:
                answer.append(i)
    if answer:
        print('Результат:', *answer , sep = '    ')
    else:
        print('Этого поля и значения нет.')
    file_in.close()

file = '0'
while True :   
    menu()
    n = int(input('Введите номер :'))
    if n == 1 or filename == '0' :
        filename = input('Введите имя файла :')
        createfile(filename)
    elif n == 2 :
        writenew(filename)
    elif n == 3 :
        export(filename)
    elif n== 4 :
        findfield_1(filename)
    elif n == 5 :
        findfield_2(filename)
    elif n == 0 :
        break