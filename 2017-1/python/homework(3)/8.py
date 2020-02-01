import numpy as np

a = np.array([0, 1, 2, 3, 4, 5], float)
b = np.array([9, 8, 7], float)

a.put([0,3],b)

print(a)

a = np.array([0,1,2,3,4,5], float)
a.put([0,3],5)

print(a)

a = np.array([1,2,3], float)
b = np.array([0,1,1], float)

print(np.dot(a,b))

a = np.array([[0,1],[2,3]], float)
b = np.array([2,3], float)
c = np.array([[1,1],[4,0]], float)

print(a)
print(np.dot(b,a))
print(np.dot(a,b))
print(np.dot(a,c))
print(np.dot(c,a))