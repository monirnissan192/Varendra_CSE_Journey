import numpy as np


def F(X):
    x, y, z = X

    if x < 0:
        raise ValueError(f"x must be non-negative for sqrt(x). Current x = {x}")

    f1 = x**2 * y * z - 2 * x * y - z**2 - 5
    f2 = 2 * x * z - z**2 * y - 8
    f3 = np.sqrt(x) + y * z - 0.5

    return np.array([f1, f2, f3])


def J(X):
    x, y, z = X

    if x <= 0:
        raise ValueError(f"x must be strictly positive for df3/dx. Current x = {x}")

    df1_dx = 2 * x * y * z - 2 * y
    df1_dy = x**2 * z - 2 * x
    df1_dz = x**2 * y - 2 * z

    df2_dx = 2 * z
    df2_dy = -z**2
    df2_dz = 2 * x - 2 * z * y

    df3_dx = 0.5 / np.sqrt(x)
    df3_dy = z
    df3_dz = y

    return np.array([
        [df1_dx, df1_dy, df1_dz],
        [df2_dx, df2_dy, df2_dz],
        [df3_dx, df3_dy, df3_dz]
    ])


def newton_raphson_solver(initial_guess, tolerance=1e-8, max_iterations=100, damping=0.3):
    X = np.array(initial_guess, dtype=float)
    print(f"\nStarting Newton-Raphson with initial guess: {initial_guess}\n")

    for i in range(1, max_iterations + 1):
        try:
            F_val = F(X)
            J_val = J(X)

            cond_number = np.linalg.cond(J_val)
            if cond_number > 1e12:
                print(f"Iteration {i}: Jacobian nearly singular (cond number = {cond_number:.2e}).")
                return None

            delta_X = np.linalg.solve(J_val, -F_val)
            norm_delta = np.linalg.norm(delta_X)

            X_new = X + damping * delta_X
            X_new[0] = max(X_new[0], 1e-8)  # Keep x >= small positive to avoid sqrt issues

            print(f"Iteration {i}: X = {X_new}, ||delta|| = {norm_delta:.3e}")

            if norm_delta < tolerance:
                print(f"\n✅ Converged in {i} iterations.")
                return X_new

            X = X_new

        except ValueError as ve:
            print(f"Iteration {i}: ValueError: {ve}")
            return None
        except np.linalg.LinAlgError as lae:
            print(f"Iteration {i}: Linear algebra error: {lae}")
            return None

    print("❌ Did not converge within max iterations.")
    return None


def verify_solution(X):
    print("\n--- Verifying Solution ---")
    F_val = F(X)
    print(f"F(X) = {F_val} (should be close to [0, 0, 0])")

    x, y, z = X
    eq1 = x**2 * y * z - 2 * x * y - z**2
    eq2 = 2 * x * z - z**2 * y
    eq3 = np.sqrt(x) + y * z

    print(f"Eq1 + 5 = {eq1 + 5:.6f} (should be 5.000000)")
    print(f"Eq2 + 8 = {eq2 + 8:.6f} (should be 8.000000)")
    print(f"Eq3 = {eq3:.6f} (should be 0.500000)")


if __name__ == "__main__":
    np.set_printoptions(precision=6, suppress=True)

    initial_guess = [1.5, 0.1, 1.0]

    solution = newton_raphson_solver(initial_guess)

    if solution is not None:
        print(f"\n✅ Found Solution: x={solution[0]:.6f}, y={solution[1]:.6f}, z={solution[2]:.6f}")
        verify_solution(solution)
    else:
        print("❌ Failed to find a valid solution.")
