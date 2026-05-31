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

A=np.array([[4,8,-1],[3,2,5],[10,7,-9]],dtype=np.float64)
print('Orginal Matrics A\n',A,'\n')
l,u=get_lu(A)
print('Reconstructed A from L and U:\n:',l @ u)
print('\nL:\n',l)
print('\nU:\n',u)