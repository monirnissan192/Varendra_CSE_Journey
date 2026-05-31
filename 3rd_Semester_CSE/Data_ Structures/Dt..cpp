#include<iostream>
#define MaxQue 10
using namespace std;
int Queue[MaxQue];
int Front=-1;
int Rear=-1;
void Qinsert(int K){
    if(Rear==MaxQue-1){
    cout<<"Queue is Overflow"<<endl;
}
else if(Front==-1&&Rear==-1){
    Front=Rear=0;
    Queue[Rear]=K;
}
else{
    Rear=Rear+1;
    Queue[Rear]=K;
}
}
void Qdelete(){
if(Front==-1&&Rear==-1){
cout<<"Queue is Undeflow"<<endl;
}
else if(Front==Rear){
Front=-1;
Rear=-1;
}
else{
Front=Front+1;
}
}
void Display(){
if(Front==-1&&Rear==-10){
cout<<"Queue is Empty"<<endl;
}
else{
for(int j=Front;j<=Rear;j++){
cout<<" Queue is :"<<Queue[j]<<endl;
}
cout<<endl;
}
}

int main(){
 int Data,n;
 cout<<"Enter the Element:";
 cin>>n;
 for(int i=0;i<n;i++){
cout<<"Enter your Data:";
cin>>Data;
Qinsert(Data);
 }
 Display();
 Qdelete();
 Qdelete();
 cout<<"After delete Queue Data is:";
 Display();
}
