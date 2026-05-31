import numpy as np

def get_polynomial_input():
    while True:
        try:
            d = int(input("Enter the degree of the polynomial (d): "))
            if d <= 0:
                print("Polynomial degree must be a positive integer.")
            else:
                break
        except ValueError:
            print("Invalid input. Please enter an integer for the degree.")

    coefficients = []
    print(f"Enter the coefficients a_k (from k=0 to k={d}):")
    for k in range(d + 1):
        while True:
            try:
                coeff = float(input(f"Enter coefficient a_{k}: "))
                coefficients.append(coeff)
                break
            except ValueError:
                print("Invalid input. Please enter a number for the coefficient.")

    if coefficients[d] == 0:
        raise ValueError(f"The leading coefficient a_{d} cannot be zero for a degree {d} polynomial.")

    return d, coefficients

def compute_companion_matrix(d, a_coeffs):
    if d <= 0:
        raise ValueError("Polynomial degree must be a positive integer.")
    if len(a_coeffs) != d + 1:
        raise ValueError(f"Expected {d + 1} coefficients for a degree {d} polynomial, but got {len(a_coeffs)}.")
    if a_coeffs[d] == 0:
        raise ValueError(f"The leading coefficient a_{d} cannot be zero for a degree {d} polynomial.")

    normalized_coeffs = [coeff / a_coeffs[d] for coeff in a_coeffs]

    companion_matrix = np.zeros((d, d))

    for i in range(d - 1):
        companion_matrix[i, i + 1] = 1.0

    for i in range(d):
        companion_matrix[d - 1, i] = -normalized_coeffs[i]

    return companion_matrix

if __name__ == "__main__":
    print("--- Companion Matrix Calculator ---")
    try:
        degree, coefficients = get_polynomial_input()

        companion_mat = compute_companion_matrix(degree, coefficients)

        # Pretty polynomial string
        terms = []
        for k in range(degree + 1):
            coeff = coefficients[k]
            if coeff == 0:
                continue
            if k == 0:
                terms.append(f"{coeff}")
            elif k == 1:
                terms.append(f"{coeff}x")
            else:
                terms.append(f"{coeff}x^{k}")
        polynomial_str = " + ".join(terms)

        print(f"\nPolynomial: p_{degree}(x) = {polynomial_str}")
        print("\nComputed Companion Matrix:")
        print(companion_mat)

        # Optional: Eigenvalues (roots)
        roots = np.linalg.eigvals(companion_mat)
        print("\nRoots of the polynomial (from eigenvalues):")
        print(roots)

    except ValueError as e:
        print(f"\nError: {e}")
    except Exception as e:
        print(f"\nAn unexpected error occurred: {e}")
