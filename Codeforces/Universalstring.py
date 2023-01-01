t = int(input())
for _ in range(t) :
    p = str(input())
    check = True
    for i in range(1,len(p)) :
        if not( p[i] == 'a' and p[i-1] == 'z' ) :
            if ord(p[i]) - ord(p[i-1]) != 1 :
                check = False
    if check :
        print('YES')
    else :
        print('NO')
