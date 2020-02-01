import numpy as np
import matplotlib.pyplot as plt
s = np.random.uniform(6,7,25)
plt.figure(1)
plt.subplot(3,1,1)
plt.hist(s,4)

height  = np.array([ 4.,  3.,  1.,  2.])
left = np.array([ 6.12859167,  6.32272242,  6.51685318,  6.71098393])


plt.subplot(3,2,2)    //pdf (height/np.size(s))
plt.bar(left,height/np.size(s),(s.max()-s.min())/4)


plt.subplot(3,2,3)    //cdf  np.cumsum()
plt.bar(left,np.cumsum(height/np.size(s)),(s.max()-s.min())/4-0.1)
