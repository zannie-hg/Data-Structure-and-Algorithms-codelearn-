#include <bits/stdc++.h>

using namespace std;
bool ktsnt(int n)
{
    
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if(ktsnt(arr[i])==true)
        cout<<arr[i]<<" ";
    }
    
    
    
    
    return 0;
}