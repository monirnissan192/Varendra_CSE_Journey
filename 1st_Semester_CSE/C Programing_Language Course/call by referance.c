#include<stdio.h>
int swap (int a ,int b);
void main(){
    int a =18,b=12;
    swap(a,b);
}
int swap(int a,int b){
    int t;
    t=a;
    a=b;
    b=t;
    printf("a=%d b=%d",a,b);
}

