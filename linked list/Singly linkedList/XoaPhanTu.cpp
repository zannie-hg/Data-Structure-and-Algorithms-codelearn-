#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *makeNode(int x){
    node *temp = new node;
    temp->next=NULL;
    temp->data=x;
    return temp;
}
void print(node *a){
    node *p =a;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

}
node *addElement(node *p, int x){
    node *temp = makeNode(x);
    p->next =temp;
    return temp;
}
node *deleteHead(node *a){
	node *p = a;
	p = p->next;
	// delete(a);
	// return p;
}
node *deleteTail(node *a){
	node *p = a;
	while (p->next->next != NULL){
		p = p->next;
	}
	delete(p->next);
	p->next = NULL;
	return a;
}
node *deleteAt(node *a, int k){
    node *p = a;
    for (int i = 0; i < k-1; i++)
    {
        p=p->next;
    }
    node *temp = p->next;
    p->next=p->next->next;
    delete temp;
    return a;

    
}
int main(){
    int n,k,x;
    cin>>n;
    cin>>x;
    node *a = makeNode(x);
    node *p = a;
    for (int i = 1; i < n; i++)
    {
        cin>>x;
        p=addElement(p,x);
    }
    cin>>k;
    if (k == 0){
		a = deleteHead(a);
	} else if (k == n-1){
		a = deleteTail(a);
	} else{
		a = deleteAt(a, k);
	}
    print(a);
    return 0;
}