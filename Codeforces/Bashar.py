n,x = map(int,input().split())
a = [int(i) for i in input().split()]
kq = n+1
if sum(a) < x :
    print('-1')
    exit(0)
cnt = a[0]
l = 0
r = 0
while l <= n-1 :
    while r < n-1 and cnt + a[r+1] < x :
        cnt += a[r+1]
        r += 1
    if cnt < x :
        if r == n-1 :
            break
        else :
            cnt += a[r+1]
            r += 1
    kq = min(kq,r-l+1)
    cnt -= a[l]
    l += 1
print(kq)