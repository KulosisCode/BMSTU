t = int(input())
operator =[' ','-']
for _ in range(t) :
    check = True 
    st = str(input())
    word = 1
    if len(st) > 100 :
        check = False
    if st[0].isupper() :
        check = False   
    for i in range(len(st)):
        if st[i].isupper(): word += 1
        if st[i] in operator :
            check = False
            break
    if word > 7 :
        check = False
    if check :
        print('YES')
    else :
        print('NO')