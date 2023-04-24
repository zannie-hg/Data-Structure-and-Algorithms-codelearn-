#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node *prev;
};
Node *makeNode(int x){
    Node *newNode = new Node;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
Node printList(Node *a){
    Node *p =a;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}
Node *addElement(Node *p, int x){
    Node *temp = makeNode(x);
    (p)->next = temp;
    temp->prev = (p);
    return temp;
}

Node *addFirst(Node *a, int x){
    Node *p = makeNode(x);
    p->next=a;
    (a)->prev = p;
    a=p;
}
Node *addLast(Node *a, int x){
    Node *p = a;
    while (p!=NULL)
    {
        p=p->next;
    }
    Node *temp = makeNode(x);
    temp->prev = p->next;
    temp->next=NULL;
    return a;
    
}
int main(){
    int n,x,k;
    cin>>n;
    cin>>x;
    Node *a = makeNode(x);
    Node *p = a;
    for (int i = 1; i < n; i++)
    {
        cin>>x;
        p = addElement(p,x);
    }
    cin >> k >> x;
	if (k == 0){
		a = addFirst(a, x);	
    } else if (k==n)
    {
       		a = addLast(a, x);	

    }
    
    printList(a);
}