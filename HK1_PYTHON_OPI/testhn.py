""" try:
    x = int(input('Nhập một số trong khoảng 1-10: '))
    if x < 1 or x > 10:
        raise Exception('Số bạn vừa nhập nằm ngoài khoảng cho phép mất rồi!')
    else :

        print ('Bạn vừa nhập một số hợp lệ :D')

except Exception :
    print( 'Số bạn vừa nhập nằm ngoài khoảng cho phép mất rồi!') """

# import numpy as np
# np.zeros((3,4),dtype=int)
# np.ones((2,3,4),dtype=int)
# np.arange(1,7,2)
# np.full((2,3),5)
# np.eye(4,dtype=int)
# arr = np.random.random((2,3))
# print(arr) 
# arr.dtype
# arr.shape
# arr.size
# arr.ndim
# arr1 = np.array([(4,5,6), (1,2,3)], dtype = int)
# print(np.min(arr1))
# b = np.identity(4)
# print(b)
# import matplotlib.pyplot as plt 
# from pylab import *
# x = [0,6,11,17,24,31,38,40]
# y = [0,2,13,10,16,12,20,17]
# plt.plot(x,y)
# plt.show()