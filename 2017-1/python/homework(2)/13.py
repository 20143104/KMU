import numpy as np

a = np.ones((2,3), dtype = float)

print(a)

a = np.zeros(7, dtype = int)

print(a)

a = np.array([[1,2,3],[4,5,6]], float)

print(np.zeros_like(a))

print(np.ones_like(a))