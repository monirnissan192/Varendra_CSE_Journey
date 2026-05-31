import numpy as np


def gaussian_elimination(A, b):
    A = A.copy().astype(np.float64)
    b = b.copy().astype(np.float64)
    n = A.shape[0]

    for i in range(n - 1):
        for j in range(i + 1, n):
            if A[i, i] == 0:
                raise ValueError("Zero pivot encountered.")
            factor = A[j, i] / A[i, i]
            A[j, i:] = A[j, i:] - factor * A[i, i:]
            b[j] = b[j] - factor * b[i]

    return A, b


def backward_substitution(U, b):
    n = U.shape[0]
    x = np.zeros(n)
    x[n - 1] = b[n - 1] / U[n - 1, n - 1]
    for i in range(n - 2, -1, -1):
        s = b[i]
        for j in range(i + 1, n):
            s -= U[i, j] * x[j]
        x[i] = s / U[i, i]
    return x


A=np.array([[3, 4, 3, 1],
              [5, 4, 3, -1],
              [5, 6, 4, 2],
              [4, 5, 8, 8]], dtype=np.float64)

b = np.array([4, 3, -2,1], dtype=np.float64)

U, modified_b = gaussian_elimination(A, b)
x = backward_substitution(U, modified_b)

print("Original Matrix A:\n", A)
print("\nUpper Triangular Matrix after Gaussian Elimination:\n", U)
print("\nModified Right-hand Side Vector after Elimination:\n", modified_b)
print("\nSolution Vector x (from Ux = b):\n", x)

print("\nVerification A @ x:\n", A @ x)
print("Original RHS b:\n", b)