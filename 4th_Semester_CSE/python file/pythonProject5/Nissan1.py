import numpy as np


def partial_pivot(A_aug, i):
    n = A_aug.shape[0]
    max_row = i

    for j in range(i + 1, n):
        if abs(A_aug[j, i]) > abs(A_aug[max_row, i]):
            max_row = j

    if max_row != i:
        A_aug[[i, max_row], :] = A_aug[[max_row, i], :]  # safer row swap


def gaussian_elimination_pivot(A, b):
    n = A.shape[0]
    x = np.zeros(n)
    A_aug = np.hstack((A.astype(float), b.astype(float).reshape(n, 1)))

    print("\nInitial Augmented Matrix:")
    print(A_aug)
    print("\n--- Forward Elimination with Partial Pivoting ---")

    for i in range(n - 1):
        print(f"\nProcessing pivot row {i}:")

        if np.isclose(A_aug[i, i], 0.0):
            print(f"  Pivot element A_aug[{i},{i}] = {A_aug[i, i]:.2e} is close to zero. Performing partial pivot.")
            partial_pivot(A_aug, i)
            print("  Matrix after pivoting:")
            print(A_aug)
            if np.isclose(A_aug[i, i], 0.0):
                print("  Error: Still near-zero pivot. System may be singular.")
                return None

        for j in range(i + 1, n):
            factor = A_aug[j, i] / A_aug[i, i]
            A_aug[j, i:] = A_aug[j, i:] - factor * A_aug[i, i:]
            print(f"  Row {j} = Row {j} - {factor:.4f} * Row {i}")

        print("  Matrix after elimination:")
        print(A_aug)

    print("\n--- Back Substitution ---")

    if np.isclose(A_aug[n - 1, n - 1], 0.0):
        print(f"  Error: Last pivot A_aug[{n - 1},{n - 1}] = {A_aug[n - 1, n - 1]:.2e} is close to zero.")
        return None

    x[n - 1] = A_aug[n - 1, n] / A_aug[n - 1, n - 1]
    print(f"  x[{n - 1}] = {x[n - 1]:.6f}")

    for i in range(n - 2, -1, -1):
        sum_ax = np.dot(A_aug[i, i + 1:n], x[i + 1:n])
        if np.isclose(A_aug[i, i], 0.0):
            print(f"  Error: Division by zero for x[{i}]. Matrix might be singular.")
            return None
        x[i] = (A_aug[i, n] - sum_ax) / A_aug[i, i]
        print(f"  x[{i}] = {x[i]:.6f}")

    return x


def solve_and_verify(A, b, title):
    print(f"\nSolving System: {title}")
    print("Matrix A:")
    print(A)
    print("Vector b:")
    print(b)

    solution = gaussian_elimination_pivot(A, b)

    if solution is not None:
        print("\n--- Solution Found ---")
        print("Solution x:")
        print(solution)
        print("Verification (A @ x - b):")
        print(np.dot(A, solution) - b)
    else:
        print("Failed to find a unique solution.")


if __name__ == "__main__":
    np.set_printoptions(precision=4, suppress=True)

    A1 = np.array([[2, 1, -1],
                   [-3, -1, 2],
                   [-2, 1, 2]])
    b1 = np.array([8, -11, -3])

    A2 = np.array([[0, 1, 1],
                   [1, 2, 3],
                   [4, 5, 6]])
    b2 = np.array([3, 6, 15])

    A3 = np.array([[1, 2, 3],
                   [2, 4, 6],
                   [7, 8, 9]])
    b3 = np.array([6, 12, 24])

    solve_and_verify(A1, b1, "System 1 (Well-posed)")
    print("\n" + "=" * 70 + "\n")
    solve_and_verify(A2, b2, "System 2 (Requires Pivoting)")
    print("\n" + "=" * 70 + "\n")
    solve_and_verify(A3, b3, "System 3 (Singular Matrix)")
