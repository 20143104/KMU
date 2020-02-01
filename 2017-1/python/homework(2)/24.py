import numpy as np

a = np.array([1,1,4,5,5,5,7], float)

print(np.unique(a))

a = np.array([[1,2],[3,4]], float)

print(a.diagonal())

a = np.array([1,3,0], float)
b = np.array([0,3,2], float)
    
print(a>b)