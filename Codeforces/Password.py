t = int(input())
for _ in range(t):
    n = int(input())
    m = list(input())
    check = True
    for i in range(1,n) :
            if m[i] == '-' : break
            else :
                for j in range(i) :
                    if m[j] > m[i] :
                        check = False
    if check :
        tich = 1 
        hieu = 0
        space = 0
        nummin = 0
        nummax = 0
        if m[0] == '-' : nummin == 0
        if n >= 2 :
            for i in range(1,n) :
                space += 1
                if not m[i-1].isdigit() :
                    nummin = int(m[i-1])
                if not m[i+1].isdigit() :
                    nummax = int(m[i+1])
                if nummax != 0 :
                    hieu = nummax - nummin +1
                    for k in range(space) :
                        
        else :
            if m[0] == '-' :
                print('9')
            else : print('0')
            


