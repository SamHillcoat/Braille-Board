import math
import os

print(os.getegid())
button_w = 60
button_h = 60
button_x = 340
button_y = 180
button_r = 10
spacing = 120
white = color(200)
black = color(100)
colour = white
done = False
clicked = False
states = [0, 0, 0, 0, 0, 0]
locked = False


class button:
    """docstring for button"""

    def __init__(self, x, y, c):
        self.x = x
        self.y = y
        self.c = c

    def new(self):
        fill(self.c)
        return ellipse(self.x, self.y, button_w, button_w)

inarea = False
buttons = []
colours = [white, white, white, white, white, white]


def setup():
    size(800, 800)
    background(255)


def draw():
    clicked = False
    #buttons = []
    # fill(200)
    noStroke()
    for i in (range(3)):
        buttons.append(button(button_x, button_y + (spacing * i), colour))
       # buttons[i].new()
        # print(buttons[i].x)
    for j in (range(3)):
        buttons.append(button(button_x + spacing,
                              button_y + (spacing * j), colour))
    # print(len(buttons))
    for i in range(6):
        buttons[i].new()
    for c in range(6):
        buttons[c].c = colours[c]
        buttons[c].new()
    
    
    
    set_colours(states)
    clicked = False
    #print(done)


def is_mouse_over(button):
    disX = mouseX - button.x
    disY = mouseY - button.y
    if (math.sqrt((disX**2) + (disY**2)) < (button_w / 2)):
        print("cheese")
        return True
    else:
        return False

def change_state(i):
    global states
    if states[i] == 0:
        states[i] = 1
    elif states[i] == 1:
        states[i] = 0
    else:
        pass
    write_to_file(states)

def mouseClicked():
    global buttons
    for i in range(6):
        if is_mouse_over(buttons[i]) is True:
            change_state(i)
            print("yes")
    print("hello")



def set_colours(states):
    for i in range(len(states)):
        if states[i] == 0:
            colours[i] = white
        elif states[i] == 1:
            colours[i] = black

def write_to_file(states):
    f = open("states.txt", "w")
    data = " ".join(str(i) for i in states)
    print(data)
    f.write(data)
    f.close()