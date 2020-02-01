import numpy as np

a = np.array([[1,3,4],[5,2,3]], float)

U, s, Vh = np.linalg.svd(a)

print(U)
print(s)
print(Vh)