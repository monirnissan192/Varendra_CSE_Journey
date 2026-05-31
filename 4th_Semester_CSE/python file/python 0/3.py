from math import exp

def f(x):
    return 0.001*exp(-x)-x-5
def f_der(x):
    return (f(x+0.05)-f(x))/0.05
def NewtonR(f,f_der,x0,eps=0.005,max_iter=3):
    xr_new=x0-(f(x0) /f_der(x0))
    ae=abs(xr_new-x0)
    x0=xr_new
    iter=1
    while ae>eps and iter<=max_iter:
        xr_new = x0 - (f(x0) / f_der(x0))
        ae = abs(xr_new - x0)
        x0 = xr_new
        iter+=1
    return x0
x0=0
xr_root=NewtonR(f,f_der,x0)
print(f'root found at{xr_root:.2f}')
print(f'f({xr_root:.2f})={f(xr_root):.2f}')