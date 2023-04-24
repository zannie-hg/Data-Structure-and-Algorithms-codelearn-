#include <bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{

    int n,arr[100];
    cin>>n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        q.push(arr[i]);
    }
    int k;
    cin>>k;

    for (int i = 0; i < k; i++)
    {
        int x =q.front();//truy xuat phan tu o dau
        q.pop();
        q.push(x);
    }
    
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    return 0;
}