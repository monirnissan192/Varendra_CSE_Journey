from math import fabs


# Function definition: f(x) = 3x^2
def f(x):
    return 3 * x * x


# True integral using the analytical formula (for f(x) = 3x^2)
def true_integral(x0, x1):
    return (x1 ** 3) - (x0 ** 3)  # Exact integral for 3x^2


# Approximate integral using the composite Trapezoidal Rule with more subintervals
def appr_integral(f, x0, x1, n):
    h = (x1 - x0) / n  # Step size
    sum_val = f(x0) + f(x1)  # Starting with f(x0) and f(x1)

    for i in range(1, n):
        sum_val += 2 * f(x0 + i * h)  # Add intermediate points

    return (h / 2) * sum_val  # Return the total approximation


# Define limits
x0 = -1
x1 = 0.5
n = 4  # Number of subintervals

# Compute values
Tv = true_integral(x0, x1)  # True integral value
Av = appr_integral(f, x0, x1, n)  # Approximate integral using Trapezoidal Rule

# Compute percentage error
Tpre = fabs((Tv - Av) / Tv) * 100

# Print results
print(f"True Value: {Tv:.6f}")
print(f"Approximate Value: {Av:.6f}")
print(f"TPRE: {Tpre:.6f} %")
