#include<stdio.h>
int main (){
    int array[]={10,20,06,02,-5,155};
    int i,*ptr;
    ptr=&array;
    printf("\n");
    for (i=0; i<6 ; i++){
    printf("array[%d] = %d ", i , array[i]);
    printf("\t------ ptr + %d = %d\n",i, *(ptr+i));
    }
   return 0;
}
