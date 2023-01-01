def phantach(value) :
    global maxv,minv
    for i in range(0,len(value),2) :
        if minv > value[i] :
            if value[i+1] >= minv :
                if maxv >= value[i+1] :
                    minv = value[i]
                elif maxv < value[i+1] :
                    minv = value[i]
                    maxv = value[i+1]
        elif minv <= value[i]:
            if  maxv < value[i+1] and maxv >= value[i] :
                maxv = value[i+1]
    
    
            
n = 0 
while n <= 0 or n > 20 :
    n = int(input('Enter N :'))
value = []
for i in range(n) :
    m,k = map(float,input().split())
    value.append(m)
    value.append(k)

sum = 0
check = True
while check :
    B = []
    maxv = value[1]
    minv = value[0]
    while True :
        mi,ma = minv,maxv
        phantach(value)
        if mi == minv and ma == maxv :
            break
    sum += (ma - mi)
    for i in range(0,len(value),2) :
        if value[i+1]< mi or value[i]> ma :
            B.append(value[i])
            B.append(value[i+1])
    if len(B) == 0 :
        check = False
    else :
        value = []
        value = B

print('sum : {:5.3f}'.format(sum))

  

