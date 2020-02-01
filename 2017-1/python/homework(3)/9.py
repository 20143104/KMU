import numpy as np

a = np.array([1,4,0], float)
b = np.array([2,2,1], float)

print(np.outer(a,b))

print(np.inner(a,b))

print(np.cross(a,b))

a = np.array([[4, 2, 0], [9, 3, 7], [1, 2, 1]], float)
print(a)

print(np.linalg.det(a))