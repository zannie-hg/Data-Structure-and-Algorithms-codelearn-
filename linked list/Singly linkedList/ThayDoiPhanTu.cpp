#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *makeNode(int x)
{
    Node *temp = new Node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}
void printList(Node *l)
{
    Node *p = l;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
Node *addElement(Node *p, int x)
{
    Node *temp = makeNode(x);
    p->next = temp;
    return temp;
}
Node *changeNode(Node *l, int a, int b)
{
    Node *p = l;
    while (p != NULL)
    {
        if (p->data == a)
        {
            p->data = b;
        }
        p = p->next;
    }
    return l;
}
int main()
{
    int n, x,a,b;
    cin >> n;
    cin >> x;
    Node *l = makeNode(x);
    Node *p = l;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    cout << "a: \n";
    cin >> a;
    cout << "b: \n";
    cin >> b;
    l = changeNode(l, a, b);
    printList(l);
    return 0;
}