from sense_hat import SenseHat, ACTION_PRESSED, ACTION_RELEASED
from time import sleep
from signal import pause
from collections import deque

sense = SenseHat()

O = [0,0,0]
X = [0, 250,0]
P = [255,255,0]
S = [0,255,0]
F = [0,0,0]

MAP = [
    S,X,O,O,O,O,O,O,
    O,X,X,X,X,O,X,O,
    O,O,O,O,O,O,O,O,
    O,X,X,X,X,O,X,O,
    O,O,X,O,O,O,X,O,
    O,O,X,O,X,X,X,O,
    O,X,X,O,O,O,O,O,
    O,O,O,O,X,X,X,F
    ]
MAP2 = [
    [O,X,O,O,O,O,O,O],
    [O,X,X,X,X,O,X,O],
    [O,O,O,O,O,O,O,O],
    [O,X,X,X,X,O,X,O],
    [O,O,X,O,O,O,X,O],
    [O,O,X,O,X,X,X,O],
    [O,X,X,O,O,O,O,O],
    [O,O,O,O,X,X,X,O]
    ]

question_mark = [
O,O,O,O,O,O,O,O,
X,X,X,O,X,X,X,O,
O,X,O,O,O,X,O,O,
O,X,O,O,O,X,O,O,
O,O,O,O,O,O,O,O,
O,O,X,X,X,X,O,O,
O,O,X,X,X,X,O,O,
O,O,O,O,O,O,O,O,]

x = 0
y = 0 
mx = 0
my = 0

dx = [0,0,1,-1]
dy = [1,-1,0,0]

result= [[[0 for de in range(2)] for row in range(8)] for k in range(8)]

index = 0

def findkey(xx, yy, sx, sy):
    
    if xx == sx and yy == sy:
        return
    #print(yy,xx)
    sense.set_pixel(xx, yy, 0,0,255)
    findkey(result[yy][xx][0], result[yy][xx][1], sx,sy)

    
    
def bfs(xx, yy):
         
    Check = [[0 for col in range(8)] for row in range(8)]
    distance = [[987654321 for col in range(8)] for row in range(8)]
       
       
    Check[yy][xx] = 1
    q = deque([xx, yy])
    distance[yy][xx] = 0
    
   
    while len(q) != 0:
        
        xx = q.popleft()
        yy = q.popleft()
        
       # print(xx, yy)

        if(xx == 7 and yy == 7):
            return 
        
        for i in range(0,4):
           nx = xx + dx[i]
           ny = yy + dy[i]
           
           print(nx, ny)
           
           if nx < 0 or ny < 0 or nx > 7 or ny > 7: continue
           if MAP2[ny][nx] == X: continue
           if Check[ny][nx] == 1: continue
           Check[ny][nx] = 1
          
          # print(distance[ny][nx], distance[yy][xx] + 1)
          # print(nx, ny)
           
           if distance[ny][nx] > distance[yy][xx] + 1:
              result[ny][nx] = [xx,yy]
              distance[ny][nx] = distance[yy][xx] + 1
              q.append(nx)
              q.append(ny)
        
    
def turn_dir():
    
    global mx, my, dirturn
    global x,y
    
    if 360 < x and 340 >= x and y >= 1.4 and y <= 5:
        return
    elif ((360 <= x and 340 >= x)or (0 <= x and 20 >= x)) and y <= 360 and y >= 270:   #TOP
        mx = mx + dx[1]
        my = my + dy[1]
        dirturn = 1
    elif ((360 <= x and 340 >= x)or (0<= x and 20 >= x)) and y >= 0 and y <= 90 : #DOWN
        mx = mx + dx[0]
        my = my + dy[0]
        dirturn = 0
    elif x >= 0 and x <= 90 : #LEFT
        mx = mx + dx[3]
        my = my + dy[3]
        dirturn = 3
    elif x <= 360 and x >= 270 : #RIGHT
        mx = mx + dx[2]
        my = my + dy[2]
        dirturn = 2
        
    c = wallcheck()  
    if c == -1:
        my = my - dy[dirturn]
        mx = mx - dx[dirturn]
    else:
        bfs(mx, my)
        refresh()
        findkey(7, 7, mx, my)
        
        

def wallcheck():
    
    global mx, my
    
    if my < 0 or mx < 0 or my > 7 or mx > 7:
        return -1
    
    if MAP2[my][mx] == X:
        return -1
       
    return 1


def refresh():
    sense.set_pixels(MAP)
    sense.set_pixel(mx, my, 255,255,0)
    
refresh()

while True:
    ori = sense.get_orientation_degrees()
    x = ori["pitch"]
    y = ori["roll"]
    turn_dir()
