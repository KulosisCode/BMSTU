import os
import ctypes
import tkinter as tk
import tkinter.messagebox as box

# Loading the library
os.add_dll_directory('C:/Users/haolu/OneDrive/Documents/PROGRAM/HK3/Lab12_c/lab_12_02_02')

lib = ctypes.CDLL('arr_lib.dll')


# void fibonacci_fill(int size, int *array)

_fibonacci_fill = lib.fibonacci_fill
_fibonacci_fill.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_fibonacci_fill.restype = None

def fibonacci_fill(n):
    array = (ctypes.c_int * n)()
    _fibonacci_fill(n, array)
    return list(array)


#void get_first_meet(int *src, int size_src, int *dst, int *dst_len);
_get_first_meet = lib.get_first_meet
_get_first_meet.argtypes = (ctypes.POINTER(ctypes.c_int),
                              ctypes.c_int,
                              ctypes.POINTER(ctypes.c_int),
                              ctypes.POINTER(ctypes.c_int))
_get_first_meet.restype = None

def get_first_meet(array, method):
    n = len(array)
    arr = (ctypes.c_int * n)(*array)
    
    if (method == 1):
        n_res = ctypes.c_int(n)
    elif (method == 2):
        n_res = ctypes.c_int(0)
        _get_first_meet(arr, n, None, n_res)
    res = (ctypes.c_int * n_res.value)()
    _get_first_meet(arr, n, res, n_res)
                       
    return n_res, list(res)


def clean():
    entry_num.delete(0, tk.END)
    entry_res1.delete(0, tk.END)
    entry_res2.delete(0, tk.END)
    entry_arr.delete(0, tk.END)
    

def input_num():
    #input
    n = entry_num.get()
    try:
        n = int(n)
    except:
        box.showerror('Error',"The number must be an integer!")
        n = 0
        return 
    if n <= 0:
        box.showerror('Error',"The number must be a positive integer!")
        n = 0
        return
    
    #process
    arr = fibonacci_fill(n)
    
    #output
    output_arr(arr, len(arr), entry_res1)


def input_arr():
    #input
    arr_str = entry_arr.get()
    try:
        arr = [int(x) for x in arr_str.split()]
    except:
        box.showerror('Error',"Failed to read array!")
        return
    n = len(arr)
    if n == 0:
        box.showerror('Error',"Array cannot be empty!")
        return
    
    #process
    global method
    n_res, res = get_first_meet(arr, method.get())
    
    #output
    output_arr(res, n_res.value, entry_res2)
    
        
    
def output_arr(arr, size, locate):
    locate.delete(0, tk.END)
    for i in range(size):
        locate.insert('insert', str(arr[i]) + ' ')


#Windows
window = tk.Tk()            
window.title('Lab 12')
window.geometry('750x600+10+10')
window['bg'] = ('mint cream')

# FILL
#task 1 fibonacci_fill
lbl_task1= tk.Label(window,text = '1)Fill an array of n elements with Fibonacci numbers.',
    font='arial 13', justify = tk.LEFT, bd = 1, bg = 'LightGreen')
lbl_task1.place(x = 10, y = 10, width = 730, height = 30, anchor= tk.NW)

lbl_num = tk.Label(window,text = 'Input n:', 
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_num.place(x = 10, y = 50, width = 100, height = 30, anchor= tk.NW)

entry_num = tk.Entry(window, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_num.place(x = 110, y = 50, width = 50, height = 30, anchor= tk.NW)

but_num = tk.Button(window, text = 'OK',font= 'arial 13', justify = tk.LEFT,
                  command = input_num, bg = 'SteelBlue1')
but_num.place(x = 200, y = 50, width = 100, height = 30)

lbl_res1= tk.Label(window,text = 'Result:',
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_res1.place(x = 10, y = 100, width = 100, height = 30, anchor= tk.NW)

entry_res1 = tk.Entry(window, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_res1.place(x = 110, y = 100, width = 600, height = 30, anchor= tk.NW)



# task 2 get_first_meet
lbl_task2= tk.Label(window,text = '2) Remove duplicates ',
    font='arial 13', justify = tk.LEFT, bd = 1, bg = 'LightGreen')
lbl_task2.place(x = 10, y = 170, width = 730, height = 30, anchor= tk.NW)

lbl_how = tk.Label(window,text = 'Allocate memory?',
    font='arial 13', justify = tk.LEFT, bd = 1, bg = 'mint cream')
lbl_how.place(x = 10, y = 210, width = 370, height = 30, anchor= tk.NW)

method = tk.IntVar() #method.get()
 
method1_checkbutton = tk.Radiobutton(text="Allocate memory with maximum possible size",
                    value=1, variable=method, font='arial 13', justify = tk.LEFT, bd = 1, bg = 'mint cream')
method1_checkbutton.select()
method1_checkbutton.place(x = 10, y = 240, width = 670, height = 30, anchor= tk.NW)

method2_checkbutton = tk.Radiobutton(text="Find the required size of the array then allocate memory",
                    value=2, variable=method, font='arial 13', justify = tk.LEFT, bd = 1, bg = 'mint cream')
method2_checkbutton.place(x = 10, y = 270, width = 670, height = 60, anchor= tk.NW)


lbl_arr = tk.Label(window,text = 'Enter the original array (separated by spaces):',
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_arr.place(x = 10, y = 350, width = 450, height = 30, anchor= tk.NW)

entry_arr = tk.Entry(window, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_arr.place(x = 10, y = 380, width = 480, height = 30, anchor= tk.NW)

but_arr = tk.Button(window, text = 'OK',font= 'arial 13', justify = tk.LEFT,
                  command = input_arr, bg = 'SteelBlue1')
but_arr.place(x = 500, y = 380, width = 100, height = 30)

lbl_res2 = tk.Label(window,text = 'Result:',
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_res2.place(x = 10, y = 420, width = 100, height = 30, anchor= tk.NW)

entry_res2 = tk.Entry(window, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_res2.place(x = 10, y = 450, width = 480, height = 30, anchor= tk.NW)

but_clean = tk.Button(window, text = 'Clear all',font= 'arial 13', justify = tk.LEFT,
                  command = clean, bg = 'SteelBlue1')
but_clean.place(x = 10, y = 550, width = 160, height = 30)

window.mainloop()