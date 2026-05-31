from math import exp

# Define the function
def f(x):
    return -exp(-(x - 4)**2)

# First derivative using central difference
def f_der(x):
    return (f(x + 0.05) - f(x - 0.05)) / (2 * 0.05)

# Second derivative using central difference
def f_der1(x):
    return (f(x + 0.05) - 2*f(x) + f(x - 0.05)) / (0.05**2)

# Newton-Raphson method to find minimum (i.e., where f'(x) = 0)
def Newton_Raphson(f_der, f_der1, x0, eps=0.005, max_iter=3):
    iter = 1
    xnew = x0 - (f_der(x0) / f_der1(x0))
    ae = abs(xnew - x0)
    x0 = xnew

    while ae > eps and iter <= max_iter:
        xnew = x0 - (f_der(x0) / f_der1(x0))
        ae = abs(xnew - x0)
        x0 = xnew
        iter += 1
    return x0

# Initial guess
x0 = 0
xr = Newton_Raphson(f_der, f_der1, x0)

# Output
print(f'Minimum found at x = {xr:.2f}')
print(f'f({xr:.2f}) = {f(xr):.2f}')

# Error from actual minimum at x = 4
error = abs(xr - 4)
print(f'Error from x = 4 is {error:.2f}')
