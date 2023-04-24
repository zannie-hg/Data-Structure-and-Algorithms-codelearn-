#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *makeNode(int x){
    node *a = new node;
    a->next=NULL;
    a->data=x;
    return a;
}
void print(node *a){
    node *p = a;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<endl;
    
}
node *addElement(node*p, int x){
	node *temp = makeNode(x); 
	p->next = temp; 
	return temp; 
}
node *addHead(node *a, int x){
	node *temp = makeNode(x);
	temp->next = a;
	a = temp;
	return a;
}
node *addAt(node *a, int k, int x){
	node *p = a;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = makeNode(x);
	temp->next = p->next;
	p->next = temp;
	
	return a;
}
node *addTail(node *a, int x){
	node *p = a;
	while (p->next != NULL){
		p= p->next;
	}
	node *temp = makeNode(x);
	temp->next = NULL;
	p->next = temp;
	return a;
}


int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	node *a = makeNode(x);
	node *p = a;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	cin >> k >> x;
	if (k == 0){
		a = addHead(a, x);	
	} else if (k == n){
		a = addTail(a, x);
	} else{
		a = addAt(a, k, x);
	}
	print(a);
	return 0;
}