
def check(st):
    global num
    dem = [0]*3
    front = num
    end = 0

    for i in range(len(st)):
        for j in range(3) :
            if st[i] == bracket_1[j] :
                dem[j] += 1
            if st[i] == bracket_2[j] :
                dem[j] -= 1
        if dem[0] == -1 or dem[1]== -1 or dem[2] ==-1 :
                break
        auto = True
        for j in range(3) :
            if dem[j] != 0 :
                auto = False
        if auto == True :
            end = i + num
            break   
    return(front,end)

bracket_1 = ['(','[','{']
bracket_2 = [')',']','}']
file = open('source.txt','r')
st_s = file.readline()
file.close()

front_st = 0
end_st = 0
num = 0
st = st_s
while True :
    length = end_st - front_st
    front,end = check(st)
    if length < end - front:
        front_st = front
        end_st = end    
    st = st[1:]
    if len(st) <= 1 :
        break
    num += 1  
length = end_st - front_st 
if length == 0:
    print('NO !')
else :
    for i in range(front_st,end_st+1):
        print(st_s[i],end ='')
    print()
    print('lenght :{}  , begin-{} ,end-{}'.format(length+1,front_st,end_st))
    