import numpy as np

a = np.array([1,4,3,8,9,2,3], float)

print(np.median(a))

a = np.array([[1,2,1,3],[5,3,1,8]], float)

c = np.corrcoef(a)

print(c)
print(np.cov(a))
