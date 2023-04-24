#include <bits/stdc++.h>
#include<queue>
using namespace std;

bool isPrime(int n){
    if(n<2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
    
}

int main()
{
   queue<int> q;
    int n; 
    cin >> n;
    for (int i = 2; i <= n, i < 10; i++){
        if (isPrime(i)){
            q.push(i);
        }
    }
    while (!q.empty()){
        for (int i = 1; i <= 9; i++){
            int k = q.front()*10 + i;
            if ( k <= n && isPrime(k)){
                q.push(k);
            }
        }
        cout << q.front() << " ";
        q.pop();
    }

 
    return 0;
}