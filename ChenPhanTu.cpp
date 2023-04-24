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
void printList(Node *a)
{
    Node *p = a;
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
Node *addFirst(Node *a, int x)
{
    Node *temp = makeNode(x);
    temp->next = a;
    a = temp;
    return a;
}
Node *addLast(Node *a, int x)
{
    Node *p = a;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *temp = makeNode(x);
    temp->next = NULL;
    p->next = temp;
    return a;
}
Node *addAt(Node *a, int k, int x)
{
    Node *p = a;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    Node *temp = makeNode(x);
    temp->next = p->next;
    p->next = temp;
    return a;
}
int main()
{
    int n, k, x;
    cin >> n;
	cin >> x;
    Node *a = makeNode(x);
    Node *p = a;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    cin >> k >> x;
    if (k == 1)
    {
        a = addFirst(a, x);
    }
    else if (k == n)
    {
        a = addLast(a, x);
    }
    else
    {
        a = addAt(a, k, x);
    }
    printList(a);
}
