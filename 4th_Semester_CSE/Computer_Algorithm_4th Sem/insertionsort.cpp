#include<iostream>
using namespace std;
int Count=0,Count1=0,Count2=0,Count3=0;
void Nissan(int arr[],int n)
{
    int j,temp;
    for(int i=1; i<n; i++)
    {
        Count++;
        temp=arr[i];
        j=i-1;
        //count++;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
            Count1++;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of the Element:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" Element"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        Count2++;
    }
    Nissan(arr,n);
    cout<<"Sorted Array :";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
        Count3++;
    }
    cout<<endl;

    cout<<"1st Counter:"<<Count<<endl;
    cout<<"2nd Counter:"<<Count1<<endl;
    cout<<"3rd Counter:"<<Count2<<endl;
    cout<<"4th Counter:"<<Count3<<endl;

    return 0;
}
