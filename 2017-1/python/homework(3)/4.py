import numpy as np

a = np.array([[0,1],[3,0]], float)
print( a.nonzero())

a= np.array([1,np.NaN,np.Inf], float)

print(a)
print(np.isnan(a))
print(np.isfinite(a))

