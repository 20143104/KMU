import numpy as np

a = np.array([1,3,0],float)

print(np.where(a!=0,1 /a,a))
print(np.where(a>0,3,2))