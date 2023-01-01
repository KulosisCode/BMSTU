from math import *
def func(list1):
    n = len(list1)
    sum = 0
    for i in range(n):
        sum +=list1[i]
    if n == 0:
        return 0
    return  sum / n

def giaithua(n):
    tich = 1
    for i in range(1,n):
        tich *= i
    return tich


list1 = list(map(int,input("Nhap n phan tu: ").split()))
n = len(list1)
# sum = 0
# for i in range(n):
#     sum +=list1[i]
# avg = sum / n
avg = func(list1)
print(avg)

