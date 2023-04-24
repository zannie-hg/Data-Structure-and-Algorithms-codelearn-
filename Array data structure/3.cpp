#include <bits/stdc++.h>
using namespace std;
// Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào hai số nguyên là k và x (0 ≤ k ≤ n).
// Hãy chèn phần tử có giá trị x vào dãy a, ở trước phần tử có chỉ số k và sau phần tử có chỉ số k-1. In mảng kết quả ra màn hình
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
    int x;
    cin>>x;
    for (int i = n; i >= k+1; i--){
		arr[i] = arr[i-1];
	}
	arr[k] = x;
	n++;
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
    
    
    return 0;
}