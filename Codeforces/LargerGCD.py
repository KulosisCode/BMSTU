
t = int(input())
for _ in range(t) :
    n,m = map(int,input().split())
    x = 5**n + 7**n
    y = 5**m + 7**m
    # x //= 2
    # y //= 2
    while True :
        if x > y : x,y = y,x
        t =  y % x
        y = x
        x = t
        if (x == 0) or (x== 1) or (x == y) :
            break 
    print(y)

