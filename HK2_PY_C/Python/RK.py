import pygame, sys, math

WIDTH = 600
HEIGHT  = 500 
FPS = 60

BLACK = (0,0,0)
WHITE = (255,255,255)
GREEN = ( 0, 255, 0)
RED = (255,0,0)
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("DIT ME MANH!")
clock = pygame.time.Clock()

flag = True
x = 200
y = 50
dx = 100
dy = 60
r = 10
running = True
while running :
    clock.tick(FPS)
    screen.fill(WHITE)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    #house
    pygame.draw.rect(screen, BLACK, (0, 300, 200,200), 2)
    #pipe
    pygame.draw.rect(screen, GREEN,(100,210, 50, 70))
    pygame.draw.rect(screen, BLACK,(100,210, 50, 70), 2)
    
    #roof
    pygame.draw.polygon(screen, RED, ((0,300), (50,200), (200,300)))
    pygame.draw.polygon(screen, BLACK, ((0,300), (50,200), (200,300)),2)
    
    #window
    pygame.draw.rect(screen, BLACK, (20, 350, 50,50), 2)
    pygame.draw.polygon(screen, BLACK, ((20, 375),(70,375)),2)
    pygame.draw.polygon(screen, BLACK, ((45, 375),(45,400)),2)
    

    pygame.draw.rect(screen, BLACK, (110, 350, 50,50), 2)
    pygame.draw.polygon(screen, BLACK, ((110, 375),(160,375)),2)
    pygame.draw.polygon(screen, BLACK, ((135, 375),(135,400)),2)
    
    #cloud
    if y <= 50 : flag = True
    if y >= 320 : flag = False
    if flag :
        y += 2
        x += 1
        dx += 0.7
        dy += 0.5
        r += 0.1
    else :
        y -= 2
        x -= 1
        dx -= 0.7
        dy -= 0.5
        r -= 0.1
    pygame.draw.ellipse(screen, BLACK, (x, y, dx, dy),2)
    xx = x + dx/ 2
    pygame.draw.circle(screen, BLACK, (xx, y - r),r, 2)
            


    pygame.display.flip()
 
    
pygame.quit()
sys.exit()
