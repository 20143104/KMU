import numpy as np

a = np.array([2,4,3], float)

print(a.sum())
print(a.prod())

print(np.sum(a))
print(np.prod(a))

a = np.array([2,1,9], float)

print(a.mean())
print(a.var())
print(a.std())

print(a.min())
print(a.max())

print(a.argmin())
print(a.argmax())