#include<iostream>
#include<algorithm>
using namespace std;
int Count=0,Count1=0,Count2=0,Count3=0;
int Binary_Search(int arr[],int n,int data)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(data==arr[mid])
        {
            Count++;
            return mid;

        }
        else if(data<arr[mid])
        {
            right=mid-1;
            Count1++;
        }
        else{
            left=mid+1;
             Count2++;
        }
    }

    return -1;
}
int main()
{
    int n;
    cout<<"Enter the number of Element: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" element:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        Count3++;
    }
sort(arr, arr + n);
    int data;
    cout<<"Enter the data you want to Search : ";
    cin>>data;
    int Result=Binary_Search(arr,n,data);
    if(Result!=-1)
    {
        cout<<"Element Found at "<<Result<<" index"<<endl;
    }
    else
    {
        cout<<"Element not Found at index";
    }
    cout<<"1st counter is:"<<Count<<endl;
    cout<<"2nd counter is:"<<Count1<<endl;
    cout<<"3rd counter is:"<<Count2<<endl;
    cout<<"4th counter is:"<<Count3<<endl;
    return 0;
}
