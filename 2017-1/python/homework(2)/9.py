import numpy as np

a = np.array([1,2], float)
b = np.array([3,4,5,6], float)
c = np.array([7,8,9], float)

print(np.concatenate((a,b,c)))
