import numpy as np

a = np.array([[4, 2, 0], [9, 3, 7], [1, 2, 1]], float)

print(np.linalg.det(a))
vals, vecs = np.linalg.eig(a)

print(vals)

print(vecs)

b = np.linalg.inv(a)

print(b)

print(np.dot(a,b))