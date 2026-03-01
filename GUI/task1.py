import tkinter as tk
import random as rd


STEP = rd.randint(15, 23)
INIT_X, INIT_Y = rd.randint(0, 400), rd.randint(100, 354)
BUTTON_WEIGHT, BUTTON_HEIGHT = rd.randint(20, 230), rd.randint(20, 230)


def move():
    global dx, dy, ax, ay, x_pos, y_pos

    new_x = x_pos + dx * STEP
    new_y = y_pos + dy * STEP

    wind_wid = window.winfo_width()
    wind_hei = window.winfo_height()

    but_wid = button.winfo_width()
    but_hei = button.winfo_height()

    if (new_x + but_wid) >= wind_wid:
        new_x = wind_wid - but_wid
        dx = -1

    if (new_x) <= 0:
        new_x, dx = 0, 1

    if (new_y + but_hei) >= wind_hei:
        new_y = wind_hei - but_hei
        dy = -1

    if (new_y) <= 0:
        new_y, dy = 0, 1

    x_pos, y_pos = new_x, new_y
    button.place(x = x_pos, y = y_pos)

def animation():
    move()
    window.after(50, animation)

window = tk.Tk()
window.geometry("500x500")
window.title('Square')
dx, dy = 1, 1

button = tk.Button(window, background = 'red', command = animation)

button.place(x = INIT_X, y = INIT_Y, width = BUTTON_WEIGHT, height = BUTTON_HEIGHT)
x_pos, y_pos = INIT_X, INIT_Y

animation()
window.mainloop()