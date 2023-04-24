#include <bits/stdc++.h>
using namespace std;
// Cho dãy a gồm n số nguyên, và dãy b gồm m số nguyên, cả hai dãy đều được sắp xếp không giảm.
// Hãy gộp hai dãy thành một dãy c, sao cho dãy c cũng là dãy không giảm. In dãy c ra màn hình, sau mỗi phần tử có đúng một dấy cách.
int a[100001], b[100001], c[100001];
int main()
{
     int n,m;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
      int size = 0; // lưu số lượng phần tử của dãy c
    int i = 0, j = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            c[size] = a[i];
            size++;
            i++;
        } else {
            c[size] = b[j];
           size++;
            j++;
        }
    }
    while (i < n){
        c[size] = a[i];
       size++;
            i++;
    }
    while (j < m){
        c[size] = b[j];
         size++;
            j++;
    }
    for (int i = 0; i < size; i++){
        cout << c[i] << " ";
    }
    return 0;
}