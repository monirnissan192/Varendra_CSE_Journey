#include<iostream>
using namespace std;
class A{
protected:
    int width,height;
public:
    int Nissan(int a,int b){
    width=a;
    height=b;
    return 0;
    }
};
class B:public A{
public:
    int Sir(){
    return(width*height);
    }
};
class C:public A{
public:
    int Sir1(){
    return(width*height)/2;
    }
};
int main(){
    B ob;
    C ob1;
    ob.Nissan(4,5);
    ob1.Nissan(5,4);
   cout<<" Sir : "<<ob.Sir()<<endl;
   cout<<" Sir1 : "<<ob1.Sir1()<<endl;
   cout<<"Hiararchical is Finish"<<endl;
return 0;
}
