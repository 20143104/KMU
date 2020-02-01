import numpy as np

a = np.array([1,2,3], float)

b=a

c= a.copy()

a[0]=0

print(a)

print(b)

print(c)