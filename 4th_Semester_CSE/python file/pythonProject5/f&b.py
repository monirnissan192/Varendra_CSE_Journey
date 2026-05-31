import numpy as np
def get_lu(A):
    n=A.shape[0]
    l=np.eye(n)
    u=A.copy()
    for j in range(0,n-1):
        for k in range(j+1,n):
            a=u[k,j]/u[j,j]
            l[k,j]=a
            u[k]=u[k]-a*u[j]
    return l,u
def forward_sub(l,b):
    n=l.shape[0]
    y=np.zeros(n)
    y[0]=b[0]/l[0,0]
    for i in range(1,n):
        s=b[i]
        for k in range(i):
            s=s-y[k]*l[i,k]
        y[i]=s/l[i,i]
    return y
def backword_sub(u,d):
    n=u.shape[0]
    x=np.zeros(n)
    x[n-1]=d[n-1]/u[n-1,n-1]
    for j in range(n-2,-1,-1):
        s=d[j]
        for k in range(j+1,n):
            s=s-x[k]*u[j,k]
        x[j]=s/u[j,j]
    return x

A=np.array([[4,8,-1],[3,2,5],[10,7,-9]],dtype=np.float64)
b = np.array([20, 13, 5], dtype=np.float64)

l,u=get_lu(A)

y = forward_sub(l, b)
x = backword_sub(u,y)

print("Original Matrix A:\n", A,'\n')
print("Reconstructed A from L and U:\n",l @ u)
print("\n Lower Triangular Matrix L\n", l)
print("\n Upper Triangular Matrix U\n", u)
print(f"\nRight-hand Side Vector b:\n{b}")
print(f"\nIntermediate Vector y (from Ly = b):\n{y}")
print(f"\nSolution Vector x (from Ux = y):\n{x}")