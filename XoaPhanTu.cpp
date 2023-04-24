#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *makeNode(int x)
{
    Node *a = new Node;
    a->next = NULL;
    a->data = x;
    return a;
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
Node *deleteFirst(Node *a)
{
    Node *p = a;
    p = p->next;
    delete (a);
    return p;
} 
Node *deleteLast(Node *a)
{
    Node *p = a;
 while (p->next->next != NULL)
 {
    p=p->next;
 }
 delete (p->next);
 p->next = NULL;
 return a;
 
}
Node *deleteAt(Node *a,int k){
    Node *p = a;
    for (int i = 0; i < k-1; i++)
    {
        p=p->next;
    }
    Node *temp = p->next;
    p->next=p->next->next;
    delete (temp);
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
    cin >> k;
    if (k == 0)
    {
        a = deleteFirst(a);
    }
    else if (k == n-1)
    {
        a = deleteLast(a);
       
    }  else{
        	a = deleteAt(a, k);
    }
    printList(a);
    return 0;
}
