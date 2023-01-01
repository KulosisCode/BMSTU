a = int(input())
b = int(input())
if (a + b) % 3 != 0 :
    print('-1')
else :
    i = 0
    while  True :
        j = int((a+b)/3-i)
        if ((2*i+1*j )== a) and(( 1*i +2*j)==b) :
            print(i,j,sep=' ')
            break
        if i * 3 > b :
            print('-1')
            break
        i += 1

