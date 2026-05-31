from math import exp,fabs
def f(x):
 return exp(-x*x)
def df(x):
 return (-2*x*exp(-x**2))
def df_appr(f,x,delx=0.05):
 return  (f(x+delx)-f(x))/delx

x=-1
Tv=df(x)
Av=df_appr(f,x)
Tpre=fabs((Tv-Av)/Tv)*100
print(Tv)
print (Av)
print(Tpre)
