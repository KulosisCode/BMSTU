t = int(input())
direc = 1
x = 0
y = 0

for _ in range(t) :
    num = 0
    m = list(map(str,input().split()))
    
    if m[0] == 'R' :
        direc = (direc + 1) % 4
    elif m[0] == 'L' :
        direc = (direc - 1) % 4
    elif m[0] == 'F' :
        num = int(m[1])
        if direc == 1 :
            y += num
        elif direc == 3 :
            y -= num
        elif direc == 2 :
            x += num
        elif direc == 0:
            x -= num

print(x,y,sep =' ')
        
