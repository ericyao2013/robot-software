import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

def discrete_circle(center, radius, samples, offset=0):
    return [center[0] + radius * np.cos(2 * np.pi * i / samples + offset) for i in range(samples)],\
           [center[1] + radius * np.sin(2 * np.pi * i / samples + offset) for i in range(samples)]

def draw_table():
    fig, ax = plt.subplots()
    ax.set_xlim((-200, 3200))
    ax.set_ylim((-200, 2200))
    ax.plot([0, 3000, 3000, 0, 0], [0, 0, 2000, 2000, 0])
    return fig, ax

def draw_polygon(ax, polygon, fill=True):
    x, y = polygon
    x.append(x[0])
    y.append(y[0])
    if fill: ax.fill(x, y)
    else:    ax.plot(x, y)

def draw_base(ax, pose, robot_size):
    draw_polygon(ax, discrete_circle((pose['x'], pose['y']), robot_size / 2, 6, pose['a']))

def draw_robot(ax, pose={'x': 0, 'y': 0, 'a': 0}):
    robot_size = 245

    draw_base(ax, pose, robot_size)

fig, ax = draw_table()
fig.set_size_inches(14.1, 10)
draw_robot(ax, {'x': 1000, 'y': 1000, 'a': np.pi/2})
fig.savefig("test.png")
