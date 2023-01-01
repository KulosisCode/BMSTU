# import pickle
# data = {
#      'a': [1, 2.0, 3, 4+6j],
#      'b': ("character string", b"byte string"),
#      'c': {None, True, False}
#      }

# with open('data.pickle', 'wb') as f:
#     pickle.dump(data, f)

# with open('data.pickle', 'rb') as f:
#     data_new = pickle.load(f)

#  print(data_new)
# #{'c': {False, True, None}, 'a': [1, 2.0, 3, (4+6j)], 'b': ('character string', b'byte string')}
file = open('info.txt','r')
for i in file :
    print(i)

"""def printfile(filename) :
file = open(filename,'r')
for line in file :
    st = line.split()
    for i in range(len(st)):  
        print('{:10s}'.format(st[i]),end ='')
        if i != len(st):
            print('|'+' '*5,end ='')
    print()
file.close()"""

def search1(filename) :
    find = input('')
    file = open(filename,'r')
    for line in file :
        st = line.split()
        for i in range(len(st)) :
            if st[i] == find :
                for j in range(len(st)):  
                    print('{:10s}'.format(st[j]),end ='')
                    if j != len(st):
                        print('|'+' '*5,end ='')
                print()