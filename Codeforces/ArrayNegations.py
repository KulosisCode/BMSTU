t = int(input())
for _ in range(t) :
    n,k = map(int,input().split())
    a = [0] + list(map(int,input().split()))
    f = [[-100000000]*(k+1)]*(n+2)
    f[0][0] = 0
    for i in range(1,n+1) :
        for j in range(min(k,i)) : 
            f[i][j+1] = max(f[i-1][j]-a[i-1], f[i-1][j]+ a[i-1])
            f[i][j] = max(f[i-1][j]+a[i-1],f[i][j])
    print(f)