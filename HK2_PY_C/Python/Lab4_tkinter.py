# Чыонг Ван Хао - ИУ7и-21Б
# Lab4 - Вариант 3
import tkinter as tk
import tkinter.messagebox as box
from  math import  *
EPS = 1e-7

def drawpoint(x, y):
    cl_point = "#1d0b8f"
    x1, y1 = (x - 3), (y - 3)
    x2, y2 = (x + 3), (y + 3)
    window.create_oval(x1, y1, x2, y2, fill= cl_point, outline= cl_point)

def drawcircle(x, y):
    cl_cir = "#08450c"
    x1, y1 = (x - radius), (y - radius)
    x2, y2 = (x + radius), (y + radius)
    window.create_oval(x1, y1, x2, y2, outline= cl_cir, width = 2)

def checkpoint(x):
    #l_10 = ['0','1', '2', '3', '4', '5', '6', '7', '8', '9']
    if x == '':
        box.showinfo('Error', 'Вводите число.')
        return 1
    instr = [i for i in x]
    for i in range(len(instr)):
        if  not instr[i].isdigit():
            box.showinfo('Error', 'Неправильный ввод .')
            return 1
    if int(x) > 800 :
        box.showinfo('Error', 'Номер вне допустимого диапазона.')
        return 1
    return 0
    

num_arr = 0
point_arr = []
def get_xy():
    global num_arr
    if checkpoint(input_x.get()) != 0 :
        return 
    if checkpoint(input_y.get()) != 0 :
        return 
    x = int(input_x.get())
    input_x.delete(0, 'end')
    y = int(input_y.get())
    input_y.delete(0, 'end')
    point_arr.append([])
    point_arr[num_arr].append(x)
    point_arr[num_arr].append(y)
    drawpoint(x, y)
    num_arr += 1


radius = 0
def get_rad():
    global radius
    if checkpoint(in_rad.get()) != 0:
        return
    radius = int(in_rad.get())

#Create circle with 2 max
amount_arr = []
def count_point():
    global radius
    amount_arr.clear()
    if len(point_arr) <= 2 :
        box.showinfo('Error', 'Мало  точек.')
        return 
    window.delete('all')
    for i in range(len(point_arr)):
        drawpoint(point_arr[i][0], point_arr[i][1])
    for i in range(len(point_arr) - 1):
        amount = 0
        for j in range(1, len(point_arr)):
            dx = point_arr[i][0] - point_arr[j][0]
            dy = point_arr[i][1] - point_arr[j][1]
            dl = sqrt(dx * dx + dy * dy)
            if ((radius - dl) > EPS)  & (dl > EPS) :
                amount += 1
        amount_arr.append(amount)
    flag = False
    for i in range(len(amount_arr) - 1):
        for j in range(i + 1, len(amount_arr)):
            if (amount_arr[i] == amount_arr[j]) & (amount_arr[i] != 0):
                str = ''
                str += "({},{})  ".format(point_arr[i][0], point_arr[i][1])
                str += "({},{})".format(point_arr[j][0], point_arr[j][1])
                result_label.config(text = str)
                drawcircle(point_arr[i][0], point_arr[i][1])
                drawcircle(point_arr[j][0], point_arr[j][1])
                flag = True
                return
    if not flag :
        box.showinfo('внимание', 'Не удалось найти 2 удовлетворительных точки' )
        return


def view_point():
    str =''
    for i in range(len(point_arr)):
        str += '({},{})\n'.format(point_arr[i][0], point_arr[i][1])     
    view_label.config(text = str) 
        

def reset_all():
    global num_arr, radius
    num_arr = 0
    radius = 0
    point_arr.clear()
    input_x.delete(0, 'end')
    input_y.delete(0, 'end')
    in_rad.delete(0, 'end')
    window.delete('all')
    view_label.config(text = "") 
    result_label.config(text = "")
    # view_label = tk.Label(root, text = '', bg = cl1)
    # view_label.place(x = 10, y = 400)

root = tk.Tk()
root.geometry("1000x800")
root.title("Points")

# Create back ground for point
back = "#99c8c9"
window = tk.Canvas(root, width=800, height=800,bg = back)
window.pack(expand=1, anchor="e")

# Create place to get input

###input point(x,y)
input_Label = tk.Label(root, text = 'Input X and Y')
label_x = tk.Label(root, text = 'X')
label_y = tk.Label(root, text = 'Y')
input_x = tk.Entry(root, width = 25)
input_y = tk.Entry(root, width = 25)
b_view = tk.Button(root,text ='View all point',width=20,command=view_point)
button_ok = tk.Button(root, text = 'Get X, Y', width=10,command=get_xy)
input_Label.place(x = 50, y = 20)
label_x.place(x = 0, y = 50)
label_y.place(x = 0, y = 80)
input_x.place(x = 20, y = 50)
input_y.place(x = 20, y = 80)
button_ok.place(x = 20, y = 110)
b_view.place(x = 20, y = 150)

#view all point
view_label = tk.Label(root, text = "")
view_label.place(x = 10, y = 400)
#view the result
result_label = tk.Label(root, text = "")
result_label.place(x = 20, y = 330)

###input radian
radius = 0
radian_Label = tk.Label(root, text = 'Input Radian')
in_rad = tk.Entry(root, width = 25)
but_R = tk.Button(root, text='Get R', width = 10, command=get_rad)
radian_Label.place(x = 60, y = 200)
in_rad.place(x = 20, y = 230)
but_R.place(x = 20, y = 255)

### result and reset
but_result = tk.Button(root, text='Result',width = 20,command = count_point)
but_result.place(x = 20, y = 300)
but_reset = tk.Button(root,text='Reset all',width = 20,command = reset_all)
but_reset.place(x = 20, y = 370)


# text = tk.Text(width=20, height=5, bg="darkgreen",
#             fg='white', wrap='word')
# text.insert('0', 'l')
# text.place(x = 0, y = 400)
# view_point

#Menu
def showinfo1():
    box.showinfo('Info', 'Программа сделана Чыонг Ван Хао.')

def showinfo2():
    box.showinfo('Info', 'Введите координаты из диапазона 0 - 800 ')

menubar = tk.Menu(root)

infomenu = tk.Menu(menubar, tearoff=0)
infomenu.add_command(label='О авторе', command=showinfo1)
infomenu.add_command(label='О программе', command=showinfo2)
menubar.add_cascade(label='Info', menu = infomenu)

root.config(menu=menubar)

root.mainloop()