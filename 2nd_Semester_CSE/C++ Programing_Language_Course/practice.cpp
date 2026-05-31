#include<iostream>
#include<climits>
using namespace std;
int Kadance(int arr[],int n)
{
    int MaxSum=INT_MIN;
    int Sum=0;
    for(int i=0; i<n; i++)
    {
       Sum+=arr[i];
    MaxSum=max(MaxSum,Sum);
    if(Sum<0){
        Sum=0;
    }
    }
    return MaxSum;
}
int main()
{
    int n;
    cout<<"Enter the Element Number:";
    cin>>n;
    int arr[n];
    cout<<"Enter the "<<n<<" element:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int MaxSum=Kadance(arr,n);
    cout<<"The Maximum Sub Array Sum is "<<MaxSum<<" ";
    return 0;
}
