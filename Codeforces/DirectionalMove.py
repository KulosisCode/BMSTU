t = int(input())
for  _ in range(t) :
    direc = 1
    n = int(input())
    m = list(input())
    for i in range(n) :
        if m[i] == '0' :
            direc = (direc + 1) % 4
        else :
            direc = ((direc -1 )+4) % 4
    if  direc == 0 :print('N')
    elif direc == 1 : print('E')
    elif direc == 2 : print('S')
    else : print('W')