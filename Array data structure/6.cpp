#include <bits/stdc++.h>
using namespace std;
// Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào số nguyên là k (0 ≤ k < n).
// Hãy xóa phần tử có chỉ số k ở trong dãy đó
int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[k])
            k = i;
    }
    cout << k;

    return 0;
}