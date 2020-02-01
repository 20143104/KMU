import numpy as np

print(np.poly([-1,1,1,10]))
print(np.roots([1,4,-2,3]))

print(np.polyint([1,1,1,1]))
print(np.polyder([1./4.,1./3.,1./2.,1.,0.]))

print(np.polyval([1,-2,0,2], 4))

x= [1,2,3,4,5,6,7,8]
y= [0,2,1,3,7,10,11,19]

print(np.polyfit(x,y,2))
