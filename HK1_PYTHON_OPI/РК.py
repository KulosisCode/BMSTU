# Чыонг Ван Хао
# ИУ7И-11Б
# РК

file = open('in.txt','r')
outfile = open('out.txt','w')

# прочтите первую строку
A = []
st= file.readline()
for el in st.split() :
    A.append(int(el))    
num = len(A)
#
Matrix = [0]*num
Matrix[0] = A
for i in range(1,num) :
    A = []
    st= file.readline()
    for el in st.split() :
        A.append(int(el))  
    Matrix[i] = A


#изменить значение матрицы
line = 1
value = 1
for j in range(num-1) :
    for i in range(line,num):
        Matrix[i][j] = value
        value += 1
    line += 1

# записать результаты в файл (out.txt )
for i in range(num) :
    for j in range(num) :
        st = str(Matrix[i][j]) + ' '
        outfile.write(st)
    outfile.write('\n')
file.close()
outfile.close()