#include<iostream>
#include<climits>
using namespace std;
int Kadanes(int arr[],int n)
{
    int MaxSum=INT_MIN;
    int CurrentSum=0;



        for(int i=0; i<n; i++)
        {
            CurrentSum+=arr[i];
            MaxSum=max(MaxSum,CurrentSum);

        if(CurrentSum<0){
        CurrentSum=0;
        }
        }
    return MaxSum;
}
int main()
{
    int n;
    cout<<"Enter the Number of the Element:";
    cin>>n;
    int arr[n];
    cout<<"Enter the "<<n<<" element"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int MaxSum=Kadanes(arr,n);
    cout<<"Maximum Sub array Sum of using Kadane's Approach : "<<MaxSum<<" ";
    return 0;


}
