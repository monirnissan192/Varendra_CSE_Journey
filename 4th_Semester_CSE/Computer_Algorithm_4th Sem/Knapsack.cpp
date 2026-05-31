#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
void FractionalKnapsack(int W,int Weights[],int Values[],int n)
{
    float Calculate_Ratio[n];
    int index[n];
    for(int i=0; i<n; i++)
    {
        Calculate_Ratio[i]=(float)Values[i]/Weights[i];
        index[i]=i;
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(Calculate_Ratio[j]<Calculate_Ratio[j+1])
            {
                float temp=Calculate_Ratio[j];
                Calculate_Ratio[j]=Calculate_Ratio[j+1];
                Calculate_Ratio[j+1]=temp;
                int tempIndex=index[j];
                index[j]=index[j+1];
                index[j+1]=tempIndex;
            }
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<"Ratio Sorted in Descending order:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" Item : "<<index[i]+1<<" Ratio : "<<Calculate_Ratio[i] <<endl;
        cout<<endl;
    }
        float TotalValue=0;
        int CurrentWeight=0;
        cout<<"Item Used in kanpsack : "<<endl;
        for(int i=0; i<n; i++)
        {
            int idx=index[i];
            if(CurrentWeight+Weights[idx]<=W)
            {
                TotalValue+=Values[idx];
                CurrentWeight+=Weights[idx];
                cout<<" Item : "<<idx+1<<" Full  "<<" ";
                cout<<endl;
            }
            else
            {
                TotalValue+=(W-CurrentWeight)*Calculate_Ratio[i];
                cout<<" Item : "<<idx+1<<" Partial : "<<(W-CurrentWeight)<<" / "<<Weights[idx]<<endl;
                break;
            }
        }
        cout<<"Maximum Value of Knapsack:"<<TotalValue<<" ";
        cout<<endl;
    }

    int main()
    {
        int W=100;
        int Weights[]= {15,35,25,50,10,30};
        int Values[]= {120,300,200,500,90,400};
        int n=sizeof(Weights)/sizeof(Weights[0]);
        FractionalKnapsack(W,Weights,Values,n);
        return 0;

    }
