import numpy as np

c = np.array([True , False , False], bool)

print(any(c))
print(all(c))

a = np.array([1,3,0], float)

print(np.logical_and(a>0,a<3))

b = np.array([True, False, True], bool)
b = np.logical_not(b)

print(b)

c = np.array([False, True, False], bool)

print(np.logical_or(b,c))
