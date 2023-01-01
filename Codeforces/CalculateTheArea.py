n = int(input())
i = 1
while True :
    if n % i == 0 :
        print(i,int(n/i),sep=' ')
        break
    i +=1