#include<iostream>
#include<algorithm>

using namespace std;

void ActivitySort(int Start[],int End[],int n)
{
    int index[n];
    for(int i=0; i<n; i++)
    {
        index[i]=i;
    }
    for(int i=0; i<n-i; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(End[j]>End[j+1])
            {
                int temp=End[j];
                End[j]=End[j+1];
                End[j+1]=temp;
                int tempindex=index[j];
                index[j]=index[j+1];
                index[j+1]=tempindex;
            }
        }
    }
    cout<<" Selected_Activities : ";
    int lastSelected=0;
    cout<<index[0]+1<<" ";

    for(int i=1; i<n; i++)
    {
        if(Start[i]>=End[lastSelected]){
        cout<<index[i]+1<<" ";
        lastSelected=i;
        }
    }
    cout<<endl;
}
int main()
{
    int Start[]= {1,3,5,2,6,8,9};
    int End[]= {4,6,7,9,10,11,11};
    int n=sizeof(Start)/sizeof(Start[0]);
    ActivitySort(Start,End,n);
    return 0;

}
