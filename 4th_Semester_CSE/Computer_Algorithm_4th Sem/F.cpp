#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int MaxCrossingSum(int arr[],int Left,int Mid,int Right){
int LeftSum=INT_MIN;
int RightSum=INT_MIN;
int Sum=0;
    for(int i=Mid;i>Left;i--){
        Sum+=arr[i];
        LeftSum=max(LeftSum,Sum);
    }
Sum=0;
for(int j=Mid+1;j<=Right;j++){
  Sum+=arr[j];
  RightSum=max(RightSum,Sum);
}
return LeftSum+RightSum;
}

int MaxSubArrayDc(int arr[],int Left,int Right){
if(Left==Right){
    return arr[Left];
}
int Mid=(Left+Right)/2;
int LeftMax=MaxSubArrayDc(arr,Left,Mid);
int RightMax=MaxSubArrayDc(arr,Mid+1,Right);
int CrossMax=MaxCrossingSum(arr,Left,Mid,Right);
return max(max(LeftMax,RightMax),CrossMax);
}
int main(){
 int n;
    cout<<"Enter the Number of the Element:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" Element:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int MaxSum=MaxSubArrayDc(arr,0,n-1);
    cout<<"Maximum SubarraySum Using Divider quanquar : "<<MaxSum<<endl;

    return 0;
}
