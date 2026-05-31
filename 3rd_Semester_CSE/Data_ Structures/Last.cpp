#include<iostream>
using namespace std;
struct Node{
int Data;
Node*Left;
Node*Right;
Node(int value){
Data=value;
Left=NULL;
Right=NULL;
}
};
Node*Insert(Node*Root,int Value){
if(Root==NULL){
return new Node(Value);
}
if(Value<Root->Data){
 Root->Left=Insert(Root->Left,Value);
}
else{
 Root->Right=Insert(Root->Right,Value);
}
return Root;
}
void Search(Node*Root,int Value){
while (Root != NULL) {
        if (Value == Root->Data) {
            cout << "Value: " << Value << " Found" << endl;
            return;
        } else if (Value < Root->Data) {
            Root = Root->Left; // Correct direction for smaller values.
        } else {
            Root = Root->Right; // Correct direction for larger values.
        }
    }
    cout << "Value: " << Value << " Not Found" << endl; // Only print once, after the loop.
}
void Inorder(Node*Root){
if(Root!=NULL){
    Inorder(Root->Left);
    cout<<Root->Data<<" ";
    Inorder(Root->Right);
}
}
void Preorder(Node*Root){
if(Root!=NULL){
    cout<<Root->Data<<" ";
    Preorder(Root->Left);
    Preorder(Root->Right);
}
}
void Postorder(Node*Root){
if(Root!=NULL){
    Postorder(Root->Left);
    Postorder(Root->Right);
    cout<<Root->Data<<" ";

}

}
int main(){
int n,Value;
Node*Root=NULL;
cout<<"Enter the Element in the Tree:";
cin>>n;
cout<<"Element is:"<<endl;
for(int i=0;i<n;i++){
cin>>Value;
Root=Insert(Root,Value);
}
cout<<"Inorder Travasrsal is:";
Inorder(Root);
cout<<""<<endl;
cout<<"Preorder Travasrsal is:";
Preorder(Root);
cout<<""<<endl;
cout<<"Postorder Travasrsal is:";
Postorder(Root);
cout<<""<<endl;

cout<<"Enter the Search Elemet:";
cin>>Value;
Search(Root,Value);
return 0;
}
