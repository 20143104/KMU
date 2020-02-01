import numpy as np

a= np.array([[6,4],[5,9]], float)

print(a>=6)

print(a[a>=6])

sel = (a>=6)

print(a[sel])

print(a[np.logical_and(a>5,a<9)])