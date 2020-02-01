import numpy as np

a = np.array([1,2,3] , float)

s = a.tostring()

print(s)

print(np.fromstring(s))
