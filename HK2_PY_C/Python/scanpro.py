#Чыонг Ван Хао - ИУ7и-21Б
import tkinter as tk

def draw_star(x, y, st):
    for i in range(3):
        my_canvas.create_oval(x,y,x+10,y+10,fill= st )
        x += 30
        if i % 2 == 0 :
            y += 30
        else:
            y -= 20
def draw_star2(x, y, st):
    for i in range(3):
        my_canvas.create_oval(x,y,x+10,y+10,fill= st )
        x += 20
        if i % 2 == 0 :
            y += 30
        else:
            y -= 20      

root = tk.Tk()
root.title("Чертеж--Чыонг Ван Хао")
root.geometry('800x600')

# Create Window
Sky = "#326fa8"
my_canvas = tk.Canvas(root, width = 800, height = 600, bg = Sky)
my_canvas.pack()
my_canvas.create_oval(-200, 250, 1000, 1000,fill="#134369")


#Draw Tower
tower = "#392769"
top_tower = "#0f0924"
#tower1
my_canvas.create_rectangle(320, 200, 425, 280,fill = tower,width=2 )
#tower 2
my_canvas.create_rectangle(340, 150, 410, 200,fill = tower, width=2 ) 
#top tower
my_canvas.create_polygon(325,150,425,150,375,95,fill = top_tower,width=3) 
window_c = "#f0ea4a"
my_canvas.create_rectangle(355,220,393,256,fill = window_c,width=3)
my_canvas.create_line(355, 238, 393, 238,width=2)
my_canvas.create_line(374, 220, 374, 256,width=2)
my_canvas.create_rectangle(360, 160, 390, 190,fill = window_c,width=3)
my_canvas.create_line(360, 175, 390,175,width=2)
my_canvas.create_line(375, 160, 375, 190,width=2)

#Draw Mountain
mountain = "#694313"
mountain2 = "#362509"
mountain3 = "#805a14"
side_m = "#2b241b"
my_canvas.create_oval(0, 330, 350, 800,outline = side_m, fill = mountain2, width=2)
my_canvas.create_oval(600, 360, 870, 1000,outline = side_m, fill = mountain, width=2)
my_canvas.create_oval(450, 330, 820, 1000,outline = side_m, fill = mountain2, width=2)
my_canvas.create_oval(100, 270, 650, 1000,outline = side_m, fill = mountain, width=2) #big mountain
my_canvas.create_oval(50,450,200,1000,outline = side_m, fill = mountain3,width=3)
my_canvas.create_oval(550,500,750,1000,outline = side_m, fill = mountain3,width=3)

#Draw Trees

    #tree1
my_canvas.create_line(150, 600, 155, 490,width=5)
my_canvas.create_line(155, 490, 175, 475,width=3)
my_canvas.create_line(155, 495, 135, 475,width=3)
my_canvas.create_line(153, 525, 100, 510,width=3)
my_canvas.create_line(120, 515, 105, 500,width=3)
my_canvas.create_line(153, 540, 200, 510,width=3)
my_canvas.create_line(150, 560, 110, 540,width=3)

    #tree 2
my_canvas.create_line(350, 600, 345, 485,width=5)
my_canvas.create_line(345, 495, 360, 475,width=3)
my_canvas.create_line(345, 515, 310, 500,width=3)
my_canvas.create_line(345, 530, 385, 510,width=3)
my_canvas.create_line(365, 520, 385, 525,width=3)
my_canvas.create_line(346, 550, 310, 535,width=3)
my_canvas.create_line(310, 535, 295, 545,width=3)
my_canvas.create_line(310, 535, 295, 525,width=3)
    #tree 3
my_canvas.create_line(500, 600, 505, 490,width=5)
my_canvas.create_line(490, 470, 505, 490,width=3)
my_canvas.create_line(510, 465, 505, 490,width=3)
my_canvas.create_line(505, 520, 530, 490,width=3)
my_canvas.create_line(502, 545, 470, 505,width=3)
my_canvas.create_line(490, 528, 465, 515,width=3)
    #tree 4
my_canvas.create_line(680, 600, 685, 490,width=5)
my_canvas.create_line(685, 505, 670, 470,width=3)
my_canvas.create_line(685, 525, 720, 500,width=3)
my_canvas.create_line(700, 515, 715, 490,width=3)

my_canvas.create_line(685, 550, 650, 515,width=3)
my_canvas.create_line(683, 565, 720, 535,width=3)



# Draw luna
my_canvas.create_oval(600,50,690,150, fill = "yellow", width=2)
my_canvas.create_oval(580,75,650,160,outline= Sky, fill = Sky,width=2)


#Draw Stars
star1="#d48911"
star2="#db1c0b"
star3="#9de3ce"
star4="#9f80d9"
star5='#0d8507'
my_canvas.create_oval(30,30,40,40,fill = star1 )
my_canvas.create_oval(100,50,110,60,fill = star2 )
my_canvas.create_oval(70,70,80,80,fill = star3 )
my_canvas.create_oval(150,40,160,50,fill = star5 )
my_canvas.create_oval(40,90,50,100,fill = star5 )
x = 30
y = 30
draw_star(x+130, y,star1)
draw_star2(x+80,y+40,star4)
x = 700
y = 130 
draw_star(x, y, star3)
draw_star2(x+30, y-5, star5)

#Draw firework 
coord = 300,250,250, 170
my_canvas.create_arc(coord, outline= "red", start=0, extent=90,style = tk.ARC)
my_canvas.create_oval(265, 165, 270, 170, fill=star2)
my_canvas.create_line(250,140,265,160, fill = "orange", width=2)
my_canvas.create_line(280,140,270,160, fill = "orange", width=2)
my_canvas.create_line(260,175,245,191, fill = "orange", width=2)
my_canvas.create_line(260,170,240,171, fill = "orange", width=2)

coord = 450,140,530,250
my_canvas.create_arc(coord, outline= "red", start=90, extent=90,style = tk.ARC)
my_canvas.create_oval(495, 140, 500, 145, fill=star2)
my_canvas.create_line(498,135,505,110, fill = "orange", width=2)
my_canvas.create_line(505,140,525,130, fill = "orange", width=2)
my_canvas.create_line(502,146,520,170, fill = "orange", width=2)
my_canvas.create_line(260,170,240,171, fill = "orange", width=2)

root.mainloop()