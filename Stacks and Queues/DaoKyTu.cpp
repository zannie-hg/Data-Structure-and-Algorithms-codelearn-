#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main()
{
    string s="codelearn";
    stack<char>st;
    for (char c : s) {
        st.push(c);
    }
    while (!st.empty())
    {
       cout<< st.top();
       st.pop();
    }
    
    
    
    return 0;
}