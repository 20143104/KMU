import numpy as np

a = np.array([[1,2],[3,4]], float)
b = np.array([[5,6],[7,8]], float)

print(np.concatenate((a,b)))

print(np.concatenate((a,b), axis = 0))
print(np.concatenate((a,b), axis = 1))