#include<iostream>
using namespace std;
void Nissan(int arr[],int n)
{
    int j,temp;
    for(int i=1; i<n; i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of the element:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" element:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    Nissan(arr,n);
    cout<<"Sorted Array:";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
