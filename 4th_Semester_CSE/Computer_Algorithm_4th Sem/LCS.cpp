#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char c1[] = "Kindness";
    char c2[] = "Goodness";

    int m = strlen(c1);
    int n = strlen(c2);

    int c[100][100];

    // DP table filling
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                c[i][j] = 0;

            }

            else if(c1[i-1] == c2[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;

            }
            else
            {
                c[i][j] = max(c[i-1][j],c[i][j-1]);

            }
            cout<<c[i][j]<<" "; //Printing the table purpose
        }
        cout<<endl;//same

    }
    cout<<endl;

    cout << "Length of LCS: " << c[m][n] << endl;

    // LCS Reconstruction
    int i = m, j = n;
    char lcs[100];
    int index = 0;

    while(i > 0 && j > 0)
    {
        if(c1[i-1] == c2[j-1])
        {
            lcs[index++] = c1[i-1];
            i--;
            j--;
        }
        else if(c[i-1][j] > c[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Print LCS in reverse
    cout << "LCS: ";
    for(int k = index - 1; k >= 0; k--)
        cout << lcs[k];
    cout << endl;

    return 0;
}
