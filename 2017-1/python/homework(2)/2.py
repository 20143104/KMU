import numpy as np

a = np.array([[1,2,3],[4,5,6]],float)

print(a)

print(a[0,0])

print(a[0,1])

print(a[1,:])

print(a[:,2])

print(a[-1:,-2:])

print(a.shape)

print(a.dtype)

print(len(a))

print(2 in a)

print(0 in a)