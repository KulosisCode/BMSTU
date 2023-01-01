from math import *

x = -1
while (x > 1) or (x <= -1) :
    x = float(input('Input x : '))
ep = float(input('Точность :'))              
y = 0
check = True
num = 0
while check :
    num += 1
    m_y = -(x**num)/num
    if abs(m_y) < ep :
        check = False
    else :
        y += m_y
        print('num= ',num,'\t m_y = {:2.3f} '.format(m_y))
print('y = {:2.3f}'.format(y))
        
