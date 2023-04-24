#include <bits/stdc++.h>
using namespace std;
// Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Hãy đưa ra một số nguyên là tổng tất cả các phần tử trong dãy đó.
int main()
{
    int n;
    cin>>n;
    int arr[100];
    int s=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        // cout<<arr[i]<<" ";
        s+=arr[i];
    }
    cout<<s;
    
    
    return 0;
}