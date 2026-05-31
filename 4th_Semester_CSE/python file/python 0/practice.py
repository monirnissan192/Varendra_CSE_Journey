def f(x):
    return (x - 5) ** 3 - 5

def falsep(f, xl, xu, eps=0.005, M=5000):
    if f(xl) * f(xu) > 0:
        print('Wrong guess of Bracket')
        return None

    xr_old = xl
    iter_count = 0

    while iter_count < M:
        xr_new = (xl * f(xu) - xu * f(xl)) / (f(xu) - f(xl))

        f_xr_new = f(xr_new)

        if f(xl) * f_xr_new < 0:
            xu = xr_new
        elif f(xl) * f_xr_new > 0:
            xl = xr_new
        else:
            print('Exact root found')
            return xr_new

        ae = abs(xr_new - xr_old)

        if ae <= eps or abs(f_xr_new) < eps:
            print("Method converged")
            return xr_new

        xr_old = xr_new
        iter_count += 1

    print('Method did not converge within the iteration limit')
    return None

# Main program
xl, xu = 4, 7
xr_root = falsep(f, xl, xu)

if xr_root is not None:
    print(f'Root found at {xr_root:.6f}')
    print(f'f({xr_root:.6f}) = {f(xr_root):.6f}')
