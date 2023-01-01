import pygame, sys, math

FPS = 60
WIDTH = 400
HEIGHT = 400
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('HA HA!')
clock = pygame.time.Clock()
ORANGE = (250,150,100)

LIGHT_BLUE = (64, 128, 255)
x_bar = 200
y_bar = 340
def bar():
    pygame.draw.rect(screen, ORANGE, (x_bar, y_bar, 90, 10))
move_x = True
move_ball = True
x,y = 200,50
r = 15
running = True
while running :
    screen.fill((255,255,255))
    for event in pygame.event.get():
        if event.type == pygame.QUIT :
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                move_x = True
            if event.key == pygame.K_LEFT:
                move_x = False
    if x_bar <= 0 :
        move_x = True
    if x_bar >= (WIDTH - 90):
        move_x = False
    if move_x :
        x_bar += 2
    else :
        x_bar -= 2
    bar()
    

    if y <= r : move_ball = True
    if (y_bar - y <= r) &( x >= x_bar) & (x <= (x_bar + 90)):
        move_ball = False
    if move_ball :
        y += 3
    else :
        y -= 3
    pygame.draw.circle(screen, LIGHT_BLUE,(x,y),r)
    pygame.display.flip()
    clock.tick(FPS)
pygame.quit()
sys.exit()
