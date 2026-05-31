from math import exp
def f(x):
   return x**x-(2*x)**x-5

def f_der(x):
    return (3*x)**x-4*x

def newton_raphson(f,f_der,x0,eps=0.005,max_iter=3):
    print(f'x0={x0:.2f}')
    xnew=x0-(f(x0)/f_der(x0))
    print(f'xnew={xnew:.2f}')
    ae=abs(xnew-x0)
    print(f'ae={ae:.2f}')
    x0=xnew
    iter=1
    while ae > eps and iter <=max_iter:
     print(f'x0={x0:.2f}')
     xnew = x0-(f(x0)/f_der(x0))
     print(f'xnew={xnew:.2f}')
     ae=abs(xnew-x0)
     print(f'ae={ae:.2f}')
     x0=xnew
     iter+=1
    return x0
x0=0
xr=newton_raphson(f,f_der,x0)
print(f'root found at{xr:.2f}')
print(f'f{xr:.2f}={f(xr):.2f}')

