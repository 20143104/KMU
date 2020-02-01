import numpy as np

a = np.array([[0,2],[3,-1],[3,5]], float)

print(a.mean(axis=0))
print(a.mean(axis=1))
print(a.min(axis=1))
print(a.max(axis=0))

