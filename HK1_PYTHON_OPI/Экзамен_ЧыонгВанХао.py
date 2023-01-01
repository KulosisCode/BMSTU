#Чыонг Ван Хао
#ИУ7И - 11Б
#Экзамен


in1 = open('in1.txt','r')
in2 = open('in2.txt','r')
out = open('out.txt','w')
out1 = open('out1.txt','w')

def change(x) :
    st = ''
    while x > 1000:
        st += 'M'
        x -= 100
    while x >= 900 :
        st += 'CM' 
        x -= 900
    while x >= 500 :
        st += 'D'
        x -= 500
    while x >= 400 :
        st += 'CD'
        x -= 400
    while x >= 100 :
        st += 'C'
        x -= 100
    while x >= 90:
        st +='XC'
        x -= 90
    while x >= 50 :
        st += 'L'
        x -= 50
    while x >= 40 :
        st += 'XL'
        x -= 40
    while x >= 10 :
        st +='X' 
        x -= 10
    while x >= 9:
        st += 'IX'
        x -= 9
    while x >= 5:
        st += 'V'
        x -= 5
    while x >= 4:
        st += 'IV'
        x -= 4
    while x >= 1:
        st += 'I'
        x -= 1
    return st
  

def center(st, lenn):
    k = len(st)
    if (maxlen - k) % 2 == 0:
        return ' ' * ((maxlen-k)//2) + st + ' ' * ((maxlen-k)//2)
    else:
        return ' ' * ((maxlen-k)//2+1) + st + ' ' * ((maxlen-k)//2)

a = in1.readline().strip()
b = in2.readline().strip()
while True:
    if int(a) < int(b):
        out.write(str(int(a)) + '\n')
        a = in1.readline().strip()
    else:
        out.write(str(int(b)) + '\n')
        b = in2.readline().strip()
    if a == '' or b == '':
        break
while a == '' and b != '':
    out.write(str(int(b)) + '\n')
    b = in2.readline().strip()
while b == '' and a != '':
    out.write(str(int(a)) + '\n')
    a = in1.readline().strip()

in1.close()
in2.close()
out.close()
inn = open('out.txt', 'r')
a = inn.readline().strip()
maxlen = -1
while a != '':
    s_t = change(int(a))
    maxlen = max(maxlen, len(s_t))
    a = inn.readline().strip()
inn.close()
inn = open('out.txt', 'r')
a = inn.readline().strip()
while a != '':
    s_t = change(int(a))
    if len(s_t) < maxlen:
        s_t = center(s_t, maxlen)
    out1.write(s_t + '\n')
    a = inn.readline().strip()
out1.close()