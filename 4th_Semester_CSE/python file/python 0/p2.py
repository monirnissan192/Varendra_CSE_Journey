from math import exp
def f(x):
    return 0.001*exp(-x)-x-5
def f_der(x):
    return (f(x+0.05)-f(x))/0.05
def Newton_Raphson(f,f_der,x0,eps=0.005,max_iter=3):
    xnew=x0-(f(x0)/f_der(x0))
    ae=abs(xnew-x0)
    x0=xnew
    iter = 1

    while ae>eps and iter<=max_iter:
        xnew = x0 - (f(x0) / f_der(x0))
        ae = abs(xnew - x0)
        x0 = xnew
        iter+=1
    return x0
x0=0
xr=Newton_Raphson(f,f_der,x0)
print(f'Root found at{xr:.2f}')
print(f'f{xr:.2f}={f(xr):.2f}')


