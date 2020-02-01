import numpy as np
import matplotlib.pyplot as plt
import scipy.integrate as ig

def simpson(f, a, b, n):
    h=(b-a)/n
    k=0.0
    x=a
    for i in np.arange(1,n/2):
        x += 2*h
        k += 4*f(x)
    for i in np.arange(2,(n/2)-1):
        x += 2*h
        k += 2*f(x)
    return (h/3)*(f(a)+f(b)+k)

def function(x): return x

x=np.arange(0, 0.8, 0.01)
f= lambda x: 0.2+25*x-200*x**2+675*x**3-900*x**4+400*x**5

sol = ig.quad(f, 0, 0.8)
re=np.real(sol)
real=re[0]
print(real)
result=simpson(function, 0.0, 0.8,10)
print(result)
# 0.5039786666666668
error=(real-result)/real*100
print(error)
# error= 69.27
# real= 1.640