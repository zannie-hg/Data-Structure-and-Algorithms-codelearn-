#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    queue<int> q; 
    bool b[1001]; // Mảng boolean để đánh dấu phần tử đã xuất hiện trong cửa sổ hay chưa
    int a[1001];
    int n, k; 
    cin >> n; 
    for (int i = 0; i < 1001; i++) {
        b[i] = false; // Khởi tạo tất cả phần tử của mảng boolean bằng false
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    cin >> k; 
    for (int i = 0; i < n; i++) { 
        if (!b[a[i]]) { // Kiểm tra phần tử này đã xuất hiện trong cửa sổ hay chưa
            if (q.size() < k) { // Nếu queue chưa đầy k phần tử, thêm phần tử này vào queue
                b[a[i]] = true; // Đánh dấu phần tử này đã xuất hiện trong cửa sổ
                q.push(a[i]); // Thêm phần tử này vào queue
            } else { // Nếu queue đã đầy k phần tử, xóa phần tử đầu tiên và thêm phần tử mới vào cuối
                b[q.front()] = false; // Xóa phần tử đầu tiên khỏi cửa sổ (đánh dấu phần tử này chưa xuất hiện)
                b[a[i]] = true; // Đánh dấu phần tử mới đã xuất hiện trong cửa sổ
                q.push(a[i]); // Thêm phần tử mới vào cuối của queue
                q.pop(); // Xóa phần tử đầu tiên khỏi queue
            }
        }
    }
    while (!q.empty()) { // In ra các phần tử còn lại trong queue
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
