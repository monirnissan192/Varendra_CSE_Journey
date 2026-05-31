from math import exp,fabs

def f(x):
    return exp(-x*x)
def df(x):
    return -2 * x * exp(-x*x)
def appr(f,x,dx=0.05):
    return (f(x+dx)-f(x-dx))/(2*dx)
x=-1
tv=df(x)
av=appr(f,x)
Tpre=fabs((tv-av)/tv)*100
print('True Value',tv)
print('Appoximate Value',av)
print('Tpre is',Tpre,'%')


