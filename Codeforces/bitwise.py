def f(x, c):
    return (x >> c) & 1

t = int(input())

for _ in range(t) :
    sum = 0
    n = int(input())
    m = list(map(int,input().split()))      
    a = []
    b = []
    for  c in range(60):
        sum_1 = 0
        sum_2 = 0 
        for i in range(n) :
            sum_1 += f(m[i],c)
            sum_2 += 1- f(m[i],c)
        a.append(sum_1)
        b.append(sum_2)
    for j in range(n) :
        sum1 = 0
        sum2 = 0
        for c in range(60) :
            sum1 +=  (2**c) *(f(m[j],c)*a[c])
            sum2 +=  (2**c)*(n - (1-f(m[j],c))*b[c])
        sum +=  sum1 * sum2
    print(sum % 1000000007)



