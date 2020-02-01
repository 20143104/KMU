import numpy as np

a = np.array([[1,4],[9,16]],float)
b = np.array([0,0,1,1,0], int)
c = np.array([0,1,1,1,1],int)

print(a[b,c])

a = np.array([2,4,6,8], float)
b = np.array([0,0,1,2,3,1], int)

print(a.take(b))

a = np.array([[0,1],[2,3]], float)
b = np.array([0,0,1], int)

print(a.take(b,axis =0))
print(a.take(b,axis =1))