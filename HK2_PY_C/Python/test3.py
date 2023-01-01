import pygame, sys, math
from pathlib import Path
import os
os.chdir(Path(__file__).parent)
H = 500
W = 600
FPS = 60
pi = 3.14
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = ( 255, 0, 0)
ORANGE = (255, 150,100)
BLUE = (64, 128, 255)
pygame.init()
screen = pygame.display.set_mode((W,H))
pygame.display.set_caption("HAHA")
clock = pygame.time.Clock()
second = pygame.Surface([200, 200])
second.fill(WHITE)

x = 50
y = 10
dx = 100
dy = 150
running  = True
alpha = 30
angle = 0

while running :
    clock.tick(FPS)
    screen.fill(WHITE)
    angle += 1
    for event in pygame.event.get():
        if event.type == pygame.QUIT :
            running = False
    pygame.draw.arc(second, BLUE, (x, y, dx, dy), pi/2, 3*pi/2,2)
    pygame.draw.arc(second, GREEN, (x, y ,dx, dy), 3*pi/2, 5*pi/2,2)

    copy = pygame.transform.rotate(second, angle)
    screen.blit((copy),(300- int(copy.get_width()/2),200 -int(copy.get_height()/2)))


    #screen.blit(second, [300,200])

    pygame.display.flip()

    
pygame.quit()
sys.exit()




#hah = pygame.image.load("C:/Users/msi/Documents/PROGRAM/HK2_PY_C/Python/r2.png")
# hah = pygame.image.load('r2.png')
# cop = pygame.transform.rotate(hah, angle)
# screen.blit((cop),(50 - int(cop.get_width()/2),50 -int(cop.get_height()/2)))