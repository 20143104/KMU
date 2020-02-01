import numpy as np

a = np.array([1,4,5], int)

for x in a:
    print (x)

a = np.array([[1,2],[3,4],[5,6]], float)

for x in a:
    print (x)

for (x,y) in a:
    print (x*y)