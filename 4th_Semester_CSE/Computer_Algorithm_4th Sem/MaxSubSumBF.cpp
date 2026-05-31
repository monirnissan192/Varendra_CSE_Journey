#include<iostream>
#include<climits>
using namespace std;
int BruteForce(int arr[],int n)
{
    int MaxSum=INT_MIN;

    for(int i=0; i<n; i++)
    {
        int Sum=0;

        for(int j=i; j<n; j++)
        {
            Sum+=arr[j];
            MaxSum=max(MaxSum,Sum);
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
    int MaxSum=BruteForce(arr,n);
    cout<<"Maximum Sub array Sum of using Brute Force Approach : "<<MaxSum<<" ";
    return 0;


}
