import numpy as np
import matplotlib.pyplot as plt

fs = 150.0
ts = 1.0/fs
t = np.arange(0,1,ts)
ff1 = 5

sqwave = 0

c1 = 1

plt.figure(1)

for loop in np.arange(1,10,1):
    #sqwave = sqwave + (1/c1)*np.sin(2*np.pi*c1*ff1*t)*/
    sqwave = sqwave + (1/c1)*np.cos(2*np.pi*c1*ff1*t)+(1/c1)*np.sin(2*np.pi*c1*ff1*t)
    plt.plot(t,sqwave)
    #c1 = c1+1
    #c1 = c1+2
    c1 = c1+2

    plt.pause(3)