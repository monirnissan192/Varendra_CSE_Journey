#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(arr[j]<=x)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void Quicksort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=Partition(arr,p,r);
        Quicksort(arr,p,q-1);
        Quicksort(arr,q+1,r);
    }
}
int main()
{
   /* int n;
    cout<<"Enter the Element Number:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" Element :"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }*/
    int arr[]={2,5,1,3,10,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    Quicksort(arr,0,n-1);
    cout<<"Sorted Array:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
