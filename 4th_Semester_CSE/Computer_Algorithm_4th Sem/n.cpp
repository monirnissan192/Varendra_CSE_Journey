#include<iostream>
using namespace std;

void Nissan( int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int Min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[Min])
        {
            Min=j;
        }
    }
    if(Min!=i)
        {
            swap(arr[i],arr[Min]);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of element:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<< " Element:"<<endl;
    for(int i=0; i<n; i++)
{
    cin>>arr[i];
}
cout<<"Sorted array:";
Nissan(arr,n);
for(int i=0; i<n; i++)
{
    cout<<arr[i]<<" ";
}
return 0;
}
