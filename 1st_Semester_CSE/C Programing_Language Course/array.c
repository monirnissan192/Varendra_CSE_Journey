#include<stdio.h>
int main(){
    int arr[50],i,n,big;
    printf("Enter the array:");
    scanf("%d",&n);
    printf("Enter %d in to array",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    big=arr[0];
    for (i=0;i<n;i++){
            if (big>arr[i])
            big=arr[i];
    }
    printf("THE ASSANDING ORDER:");
    for(i=1;i<big;i++)
        for(int j=0;j<n;j++)
        if(i==arr[j])
        printf("%d\n",i);
     return 0;
}
