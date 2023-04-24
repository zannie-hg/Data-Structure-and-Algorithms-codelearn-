#include <bits/stdc++.h>
#include <stack>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i) == true)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

    return 0;
}