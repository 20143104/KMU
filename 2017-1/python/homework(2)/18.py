import numpy as np

a = np.zeros((2,2), float)
b = np.array([-1,3], float)

print(a)

print(b)

print(a+b)

print(a+b[np.newaxis,:])

print(a+b[:,np.newaxis])