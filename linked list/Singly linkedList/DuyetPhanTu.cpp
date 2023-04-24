#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *makeNode(int x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}
void print(node *a)
{
    node *p = a;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
node *addElement(node *p, int x)
{
    node *temp = makeNode(x);
    p->next = temp;
    return temp;
}
node *getNode(node *a, int k){
	node *p = a;
	for (int i = 0; i < k; i++){
		p = p->next;
	}
	return p;
}
int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    node *a = makeNode(x);
    node *p = a;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    int k;
    cin>>k;
   p = getNode(a, k);
    cout<<p->data;
    return 0;
}