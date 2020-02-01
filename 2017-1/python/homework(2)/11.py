import numpy as np

a = np.array([1,2,3], float)

print(a)

print(a[:,np.newaxis])

print(a[:,np.newaxis].shape)

print(a[np.newaxis,:])

print(a[np.newaxis,:].shape)

