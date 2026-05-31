#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{

int Data;

struct Node*Next;

};
int main(){

struct Node*Head;
struct Node*One=new Node();
struct Node*Two=new Node();
struct Node*Three=new Node();
struct Node*Four=new Node();
struct Node*Five=new Node();

Head=One;
One->Next=Two;
Two->Next=Three;
Three->Next=Four;
Four->Next=Five;
Five->Next=NULL;

One->Data=1;
Two->Data=2;
Three->Data=3;
Four->Data=4;
Five->Data=5;

struct Node*Ptr;
Ptr=Head;

while(Ptr!=NULL){
    cout<<Ptr->Data<<endl;
    Ptr=Ptr->Next;
}
}

