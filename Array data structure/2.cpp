#include <bits/stdc++.h>
using namespace std;
// Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a.
// Hãy thay đổi giá trị của mỗi phần tử thành bình phương của chính nó
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
        cout<<arr[i]*arr[i]<<" ";
        // s+=arr[i]*arr[i];
    }
    // cout<<s;
    return 0;
}