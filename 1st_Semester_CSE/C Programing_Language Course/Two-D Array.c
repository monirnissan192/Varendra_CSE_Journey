#include<stdio.h>
void main (){
    int a[10][10],b[10][10],c[10][10],i,j,k;
    int sum=0;
    printf("\n enter the first matrix:\n");
    for (i=0;i<3;i++){
    for (j=0;j<3;j++){
    scanf("%d",&a[i][j]);
    }}
    printf("\n enter the 2nd matrix:\n");
    for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                    scanf("%d",&b[i][j]);
            }}
            printf("\n enter the 1st matrix:\n");
            for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                            printf("%d",a[i][j]);}
                    printf("\n");
                    }
            printf("\n enter the 2nd matrix:\n");
            for (i=0;i<3;i++){
                    for (j=0;j<3;j++){
                            printf("%d",b[i][j]);}
                            printf("\n");
            }
            for (i=0;i<3;i++){
                    for(j=0;j<3;j++){
                            sum=0;
                    for (k=0;k<3;k++){
                            sum=sum+a[i][k]*b[k][j];
                    }
                    c[i][j]=sum;
                    }}
                    printf("\n enter the multiplication:\n");
                    for (i=0;i<3;i++){
                            for(j=0;j<3;j++){
                                    printf("%d",c[i][j]);}
                                    printf("\n");
                    }}

