#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *makeNode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void printList(Node *a){
    Node *p = a;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

Node *addElement(Node *p, int x){
    Node *temp = makeNode(x);
    p->next = temp;
    temp->prev = p;
    return temp;
}

Node *deleteFirst(Node **a){
    Node *p = *a;
    *a = p->next;
    (*a)->prev = NULL;
    delete p;
    return *a;
}

Node *deleteLast(Node **a){
    Node *p = *a;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
    delete p;
    return *a;
}

Node *deleteAt(Node **a, int k){
    Node *p = *a;
    if (k == 0)
    {
        *a = p->next;
        if (*a != NULL)
        {
            (*a)->prev = NULL;
        }
        delete p;
        return *a;
    }
    for (int i = 0; i < k-1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return *a;
        }
    }
    p->prev->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }
    delete p;
    return *a;
}

int main(){
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
    if (k == 1){
        a = deleteFirst(&a);
    } else if (k==n)
    {
        a = deleteLast(&a);
    } else {
        a = deleteAt(&a,k);
    }
    printList(a);
    return 0;   
}