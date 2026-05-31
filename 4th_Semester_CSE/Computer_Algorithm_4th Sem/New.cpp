#include<iostream>
using namespace std;
int Ls(int arr[],int L,int X){
for(int i=0;i<L;i++){
 if(arr[i]==X){
    return i;
 }
}
return -1;
}
int main(){
int arr[]={12,3,43,5,67,34,23,45,21,4};
int size=sizeof(arr);
int X;
cout<<"Enter your Nu8mbre:";
cin>>X;
int result=linearSearch(arr,L,X)
if(result!=-1){
cout<<"Element found at index:";
}
else {
cout<<"Element not found:";
}
}
