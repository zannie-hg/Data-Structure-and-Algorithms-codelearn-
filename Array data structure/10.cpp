#include <bits/stdc++.h>
using namespace std;
int main()
{
   
    int n,m,arr[100][100];
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int sum=0;
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum+=arr[i][j];
        }
        
    }
    cout<<sum;
    
    return 0;
}