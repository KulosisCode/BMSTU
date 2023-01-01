# Чыонг Ван Хао 
# ИУ7И-11Б
# Отчет - Ханойские башни.


#Подсчитывать приращения и убытки дисков на стержнях после одного шага
def amount(source,target) :
    global numA,numB,numC
    if source == 'A' :
        numA -= 1
    elif source =='B' :
        numB -= 1
    elif source == 'C' :
        numC -= 1
    if target == 'A' :
        numA += 1 
    elif target == 'B' :
        numB += 1
    elif target == 'C' :
        numC += 1

#переместить диски 
def TowerOfHanoi(n , source, target, helper):   
    global num,m
    if num >= m :
        return 
    if n==1:
        # Move disk № 1 from source to target
        amount(source,target)
        num += 1
        return    
    TowerOfHanoi(n-1, source, helper, target) 
    if num >= m :
        return 
    # Move disk n from the current to another position without affecting disk  №1
    amount(source,target)
    num += 1
    if num >= m :
        return
    else:
        # Move n-1 discs from helper to target
        TowerOfHanoi(n-1, helper, target, source) 
                     
# main
file = open('text.txt','r')
outfile = open('out.txt','w')

while True :
   
    # n-the number of disks, m-the number of the last move
    n,m = map(int,file.readline().split())
    if n == 0 and m == 0 :
        break
    elif (n < 1) or (n > 100) or (m < 0 ) or (m > 2**n-1):
        outfile.write('Error data input ! \n')
        continue
    else :
        num = 0             # number of step working       
        numA = n               # number of disks on rod A
        numB = 0               # number of disks on rod B
        numC = 0               # number of disks on rod B
        TowerOfHanoi(n,'A','C','B')
        st = str(numA)+' '+ str(numB)+' ' +str(numC) + '\n'
        outfile.write(st)

file.close()
outfile.close()




