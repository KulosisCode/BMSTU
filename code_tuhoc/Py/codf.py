z = int(input())
for _ in range(z) :
    n = int(input())
    m = list(map(int,input().split()))
    s = s_1 = 0
    for i in range(n) :
        s = max(s,sum(m[:i+1]))
    n = int(input())
    m1 = list(map(int,input().split()))
    for i in range(n) :
        s_1 = max(s_1,sum(m1[:i+1]))
    print(s+s_1)