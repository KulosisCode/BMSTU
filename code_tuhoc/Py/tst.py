# x =  int(input())

# arr = str(x)

# sub_res = ''
# sub = ''
# max_str  = 0
# flag = False

# len_str = 1
# for i in range(1,len(arr)):
#     if arr[i] >= arr[i - 1]:
#         flag = True
#         len_str += 1
#         sub = sub + arr[i]
#     else:
#         flag =  False
#         len_str = 1
#         sub = arr[i]
#     if max_str < len_str :
#         max_str = len_str
#         sub_res = sub

# print(sub_res)


# direction = [[2,1],[2,-1], [-2,1],[-2, -1], [1, 2],[1,-2],[-1,2],[-1,-2]]
# m,n = list(map(int, input().split()))

# danhsach = []
# def adding(danhsach):
#     x,y = m,n
#     danhsach.append([x,y])
#     for i in len(direction)
#     print(danhsach)
# adding()
# print(danhsach)

# l = list(input().split())
# n = []
# for i in l:
#     n.append(i.capitalize())
# print(n)

# x1,y1,x2,y2,x3,y3 = map(int,input().split())
# area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)
# if area == 0:
#     print('No')
# else:
#     print('Yes')

ds =  []
    
for i in range(3):
    ds.append([])
    for j in range(3):
        x = int(input())
        ds[i].append(x)
for i in range(3):
    for j in range(3):
        print(ds[i][j], end=' ')
    print()