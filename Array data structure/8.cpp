#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main()
{
     int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool kt1 = true; // kiểm tra dãy tăng.
    bool kt2 = true; // kiểm tra dãy giảm.
    for (int i = 1; i < n; i++){
        if (a[i] <= a[i-1]) kt1 = false;
        if (a[i] >= a[i-1]) kt2 = false;
    }
    if (kt1 || kt2) cout << "YES";
    else cout << "NO";

    return 0;
}