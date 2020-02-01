import numpy as np
import matplotlib.pyplot as plt
fs = 150
ts = 1.0/fs
t = np.arange(0,1,ts)
ff1=1
c1 =1
plt.subplot(3,1,1)
f1 = (1/1)*np.sin(1*2*np.pi*ff1*t)
plt.plot(t,f1)
plt.subplot(3,1,2)
f3 = (1/3)*np.sin(3*2*np.pi*ff1*t)
plt.plot(t,f3)
plt.subplot(3,1,3)
f5 = f1+f3
plt.plot(t,f5)