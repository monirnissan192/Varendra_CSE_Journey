#include<stdio.h>
int niloy(int a ,int b);
void main(){
    int x,y,result;
    scanf("%d%d",&x,&y);
    result=niloy(x,y);
    printf("\nthe results of Niloy=%d\n",result);
    return 0;
}
int niloy(int a,int b){
int niloy;
niloy=a+b;
return niloy;
}
