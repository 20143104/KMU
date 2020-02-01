#trapezoidal
import numpy as np
import matplotlib.pyplot as plt
import scipy.integrate as ig

x  = np.arange(0,0.8,0.01)

f = lambda x: 0.2+25*x-200*x**2 + 675*x**3-900*x**4+400*x**5

sol = ig.quad(f,0,0.8)    # 2차 원이상에서 의적분함 수
re = np.real(sol) #실 수부분 만남기 자
real = re[0]    # 실 수부분만

plt.figure(1)
plt.plot(x,f(x), 'ro-')


I = (0.8-0)*((f(0.8) + f(0)) /2)
trap = np.ones(80) *(f(0.8)+f(0))/2
plt.plot(x, trap, 'b*-')

error=(real-I)/real *100
