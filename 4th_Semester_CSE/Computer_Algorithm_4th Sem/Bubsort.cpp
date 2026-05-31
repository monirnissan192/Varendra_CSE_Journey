#include<iostream>
using namespace std;
int Count1=0,Count2=0,Count3=0,Count4=0;
void Nissan(int arr[],int n)
{
    int j,temp;
    for(int i=0; i<n; i++)
    {
        //flag=0;
        Count1++;
        for(j=0; j<n-1-i; j++)
        {
            Count2++;
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                Count3++;
            }
        }
       // if(flag==0){
          //  break;
       // }
    }
}
int main()
{
    int n;
    cout<<"Enter the Number of the Element:";
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
        Count4++;
    }
    cout<<endl;
    cout<<"1st counter:"<<Count1<<endl;
    cout<<"1st counter:"<<Count1<<endl;
    cout<<"1st counter:"<<Count1<<endl;
    cout<<"1st counter:"<<Count1<<endl;
    return 0;
}
