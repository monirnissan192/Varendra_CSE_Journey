#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the element number:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter "<<n<<" element"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
   sort(arr.begin(), arr.end() , greater<int>());

    cout<<"Sorted Array:";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
