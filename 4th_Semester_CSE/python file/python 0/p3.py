def f(x):
    return (x - 5) ** 3 - 5

def f_bisec(f, xl, xu, eps=0.005, M=5000):

    if f(xl) * f(xu) > 0:
        print("Wrong guess of the bracket")
        return None

    xr_old = xl
    iter_counter = 0

    while iter_counter < M:

        xr_new = (xl+xu)/2


        if f(xl) * f(xr_new) < 0:
            xu = xr_new
        elif f(xl) * f(xr_new) > 0:
            xl = xr_new
        else:

            print("Exact root found.")
            return xr_new


        ae = abs(xr_new - xr_old)


        if ae <= eps or abs(f(xr_new)) < eps:
            print("Method converged.")
            return xr_new


        xr_old = xr_new
        iter_counter += 1

    print("Method did not converge within the iteration limit")
    return None


xl, xu = 4, 7
xr_root =f_bisec (f, xl, xu)
if xr_root is not None:
    print(f'Root found at {xr_root:.6f}')
    print(f'f({xr_root:.6f}) = {f(xr_root):.6f}')