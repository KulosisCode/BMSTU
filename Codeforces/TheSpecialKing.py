t = int(input())
result = 0
for _ in range(t) :
    x1,y1,x2,y2 = map(int,input().split())
    result = abs(x1-x2) + abs(y1-y2)
    print(result)