def findgame(a,b) :
    num = 0
    for i in range(len(a)) :
        check = False
        for j in range(len(b)) :
            if a[i] == b[j] :
                check = True
                break
        if check == True : num +=1
    return(num)

a = list(set(input().split()))
b = input().split()
c = input().split()
n1 = len(b)
n2 = len(c)
b = list(set(b))
c = list(set(c))
x = findgame(a,b)/n1
y = findgame(a,c)/n2
if x < y  :
    print('NUMBER ONE IS THE HUMAN')
else :
    print('NUMBER TWO IS THE HUMAN')