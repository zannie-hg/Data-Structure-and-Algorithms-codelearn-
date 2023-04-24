#include <bits/stdc++.h>
using namespace std;
// Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào số nguyên là k (0 ≤ k < n).
// Hãy xóa phần tử có chỉ số k ở trong dãy đó
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
   
    for (int i = k; i <= n-1 ; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    
    return 0;
}