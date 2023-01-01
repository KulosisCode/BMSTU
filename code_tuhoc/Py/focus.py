
def out(A,N):
    for i in range(N) :
        for j in range(N) :
            print('{:3d}'.format(A[i][j]),end=' ')
        print()

N_1 = -1
while N_1< 0 or N_1 > 17:
    N_1 = int(input('Enter N :')) 
A = []
for i in range(N_1) :
    A.append([])
    for j in range(N_1) :
        A[i].append(0)

value = int(N_1*(N_1+1)/2)
N = N_1
line = 0
first = 0
end = N
cheo = 0
while True :
    for j in range(first,N) :
        A[line][j] = value
        value -= 1
    first += 2
    line += 1
    for i in range (line,end) :
        A[i][N-1] = value
        value -= 1
    end -= 2
    if value <= 0 :
        break
    num = N - 2
    for i in range(N-2-cheo,line-1,-1):
        A[i][num] = value
        value -= 1
        num -= 1
    cheo += 1

    if value <= 0 :
        break
    N -= 1

out(A,N_1)
print()
for i in range(N_1) :
    for j in range(N_1) :
        if A[i][j] == 1 :
            remember = i
del(A[remember])
for i in range(N_1-1) :
        for j in range(N_1) :
            print('{:3d}'.format(A[i][j]),end=' ')
        print()