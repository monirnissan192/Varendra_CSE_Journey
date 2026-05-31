//Push & Pop in Stack
#include<iostream>
#define MaxStk 5
using namespace std;
int Stack[MaxStk];
int Top=-1;
void Push(int n){
if(Top==MaxStk-1){
cout<<"Stack Overflow";
}
Top=Top+1;
Stack[Top]=n;
}

void Pop(){
if(Top==-1){
cout<<"Stack Underflow";
}

cout<<"Poped is:"<<Stack[Top]<<endl;
Top=Top-1;
}

void Display(){
if(Top<0){
cout<<"Stack is Not Fill up"<<endl;
}
cout<<"Stack is:";
for(int j=Top;j>=0;j--){
cout<< Stack[j]<<"";
}
cout<<endl;
}
int main(){
for( int S=0; ;S++){
int W;
cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exist"<<endl;
cin>>W;
if(W==1){
int Data,n;
cout<<"Enter the insert Data:";
cin>>n;
for(int i=0;i<n;i++){
cout<<"Enter Your Data:";
cin>>Data;
Push(Data);
}
Display();
}
else if(W==2){
Pop();
}
else if(W==3){
Display();
}
else{
return 0;
}
}
}
