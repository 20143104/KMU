import numpy as np

def sech(x):
    return np.cosh(x)**(-1)

def newton(func,dfunc,xr):
    maxit = 50
    es = 1.0-5
    iter = 0

    while(1):
        xrold = xr
        xr = np.float(xr-func(xr)/dfunc(xr))
        iter = iter+1

        if xr!=0:
            ea =np.float(np.abs(np.float(xr) - np.float(xrold))/np.float(xr)*100)

        if np.int(ea<=es) | np.int(iter>=maxit):
            root = xr
            fx = func(xr)
            return root, fx, ea, iter

g = 9.81; cd = 0.25; v=36; t = 4;

fp = lambda m : np.sqrt(g*m/cd)*np.tanh(np.sqrt(g*cd/m)*t)-v
dfp = lambda m :(1/2)*np.sqrt(g/(m*cd))*np.tanh(np.sqrt(g*cd/m)*t)-g*t/(2*m)*(sech(np.sqrt(g*cd/m)*t))**2

newton(fp,dfp,140)





