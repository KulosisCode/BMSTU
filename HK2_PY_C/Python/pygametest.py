import pygame, sys
 
FPS = 60
WIN_WIDTH = 400
WIN_HEIGHT = 100
WHITE = (255, 255, 255)
ORANGE = (255, 150, 100)
 
pygame.init()
screen = pygame.display.set_mode((WIN_WIDTH, WIN_HEIGHT))
pygame.display.set_caption("TITLE!")
# img = pygame.image.load("r2.png")
# pygame.display.set_icon(img)

clock = pygame.time.Clock()
r = 50
x = WIN_WIDTH - r
y = WIN_HEIGHT/2

check = True
running = True
while  running:

    screen.fill(WHITE)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # pygame.draw.circle(screen,ORANGE,(x,y), r)
    pygame.draw.rect(screen,ORANGE,pygame.Rect(0,0, 50, 50))
    if check :
        x += 3
    else : x -= 3
    if x >= WIN_WIDTH - r :
        check = False
    if x <= r:
        check = True
    pygame.display.flip()
    clock.tick(FPS)


pygame.quit()
sys.exit()