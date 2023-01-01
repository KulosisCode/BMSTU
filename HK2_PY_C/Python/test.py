import pygame, sys, math

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (125, 125, 125)
LIGHT_BLUE = (64, 128, 255)
GREEN = (0, 200, 64)
YELLOW = (225, 225, 0)
PINK = (230, 50, 230)
ORANGE = (255, 150, 100)

FPS = 60
WIDTH = 500
HEIGHT = 500

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("HA HA!")
clock = pygame.time.Clock()

r = 30
x = x1 = WIDTH/2
y = y1 = r 

x_center = WIDTH/2
y_center = HEIGHT/2

x_rec = 250
y_rec = 250
dx = 30
dy = 30
alpha = 0
rad = True
flag_rectx = True
flag_recty = True

running = True 
while  running:
    clock.tick(FPS)
    screen.fill(WHITE)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT :
            running = False
    
    pygame.draw.rect(screen, LIGHT_BLUE, (x_rec - dx, y_rec - dy, 2*dx, 2 * dy))
    pygame.draw.circle(screen, ORANGE, (x1,y1), r)
    x1 = x_center + (x - x_center)*math.cos(math.radians(alpha)) - (y - y_center)*math.sin(math.radians(alpha))
    y1 = y_center + (y - y_center)*math.cos(math.radians(alpha)) + (x - x_center)*math.sin(math.radians(alpha))
    alpha += 1
    alpha  %= 360
    if dx >= 50 :
        flag_rectx = False
    if dx <= 20 :
        flag_rectx = True
    if dy >= 50 :
        flag_recty = False
    if dy <= 20 :
        flag_recty = True
    if flag_rectx : dx += 1
    else : dx -= 1
    if flag_recty: dy += 1
    else : dy -= 1 
    if r >= 50 :
        rad = False
    if r <= 20 :
        rad = True

    if rad :
        r += 2
    else : r -= 2
    pygame.display.flip()
pygame.quit()
sys.exit()