x,y = map(int,input().split())
m = list(input())
for i in range(len(m)) :
    if m[i] =='U' : y +=1
    elif m[i] == 'D' : y -=1
    elif m[i] == 'L' : x -= 1
    elif m[i] == 'R' : x += 1
print(x,y,sep =' ')