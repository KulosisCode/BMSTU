import pygame, sys
from pygame.locals import *
FPS = 60

pygame.init()

#set screen
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption('Lab_05')
icon = pygame.image.load('c:/Users/msi/Downloads/anhr/radar.png')
pygame.display.set_icon(icon)
clock = pygame.time.Clock()

#balloon
balloon = pygame.image.load('c:/Users/msi/Downloads/anhr/py/ball2.png')
ball_x, ball_y = 550, 280
def ball_move():
    screen.blit(balloon, (ball_x, ball_y))


#rocket
rocket = pygame.image.load('c:/Users/msi/Downloads/anhr/py/r3.png')
rock_x, rock_y = -100, 100
def rocket_move():
    screen.blit(rocket,(rock_x, rock_y))

#Trunk
trunk = pygame.image.load('c:/Users/msi/Downloads/anhr/py/trunk.png')
trunk_x, trunk_y = 50, 310
def trunk_pos():
    screen.blit(trunk,(trunk_x, trunk_y))

#waterfall
waterfall = pygame.image.load('c:/Users/msi/Downloads/anhr/py/water5.png')
water_x, water_y = 0, 380
def water():
    screen.blit(waterfall,(water_x, water_y))

#cloud and sun
sun = pygame.image.load('c:/Users/msi/Downloads/anhr/py/sun.png')
def sun_pos():
    screen.blit(sun,(700, 80))
cloud = pygame.image.load('c:/Users/msi/Downloads/anhr/py/cloud.png')
cloud_x, cloud_y = 700, 100
id_cloud = True 
def cloud_move():
    screen.blit(cloud, (cloud_x, cloud_y))

#bullet
bullet = pygame.image.load('c:/Users/msi/Downloads/anhr/py/bullet.png')
bullet_x, bullet_y = 120, 310
def bullet_move():
    screen.blit(bullet, (bullet_x, bullet_y))

#explosion
explosion = pygame.image.load('c:/Users/msi/Downloads/anhr/py/exp1.png')
exp_x, exp_y = 380, 60
def exp1():
    screen.blit(explosion,(exp_x, exp_y))
explosion2 = pygame.image.load('c:/Users/msi/Downloads/anhr/py/exp2.png')
def exp2():
    screen.blit(explosion2, (exp_x - 60, exp_y - 100))

# Main loop
running = True
while  running :
    clock.tick(FPS)
    screen.fill((124, 193, 204))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # set no-move things
    water()
    trunk_pos()
    sun_pos()

    #set cloud
    if cloud_x < 690 : id_cloud = False
    if cloud_x > 710 : id_cloud = True
    if (id_cloud): cloud_x -= 0.3
    else: cloud_x += 0.3
    cloud_move()

    #set balloon
    ball_y -= 0.7
    ball_move()

    #set rocket
    if rock_x < 400:
        rocket_move()
        rock_x += 2
        
        #set bullet
        if (rock_x > 250) & (rock_x < 400) & (bullet_y > 100):
            bullet_move()
            bullet_x += 5
            bullet_y -= 4
            
    #set explosion
    if rock_x > 370 :
        ball_x += 0.3
        if id_cloud :
            exp1()
        else :  exp2()

    pygame.display.flip()

pygame.quit()
sys.exit()
