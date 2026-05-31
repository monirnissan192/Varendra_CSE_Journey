#include<iostream>
#define MaxQue 20
using namespace std;
int Queue[MaxQue];
int Front=-1;
int Rear=-1;
void Display();
void Qinsert(int k){
if(Rear==MaxQue-1){
cout<<"Queue is Overflow";
}
else if(Front==-1&&Rear==-1){
Front=Rear=0;
Queue[Rear]=k;
}
else{
 Rear=Rear+1;
 Queue[Rear]=k;
 Display();
}
}
void Qdelete(){
if(Front==-1&&Rear==-1){
cout<<"Queue is Underflow";
}
else if(Front==Rear){
Front=Rear=-1;
}
else{
 Front=Front+1;
 Display();
}
}
void Display(){
if(Front==-1&&Rear==-1){
cout<<"Queue is Empty:";
}
else{
for(int j=Front;j<=Rear;j++){
cout<<"Queue is:"<<Queue[j]<<endl;
}
cout<<""<<endl;
}
}
int main(){
while(true){
int w;
cout<<"1.Insert"<<endl<<"2.Delete"<<endl<<"3.Display"<<endl<<"4.Exist"<<endl;
cin>>w;
if(w==1){
int n,Data;
cout<<"Enter the Element:";
cin>>n;
for(int i=0;i<n;i++){
cout<<"Data is:";
cin>>Data;
Qinsert(Data);
}
}
else if(w==2){
int del;
cout<<"How many data do you want to delete:";
cin>>del;
for(int i=0;i<del;i++){
Qdelete();
}
}
else if(w==3){
cout<<""<<endl;
Display();
}
else if(w==4){
return 0;
}
else{
cout<<"Invalid input:"<<endl;
}
}
}
