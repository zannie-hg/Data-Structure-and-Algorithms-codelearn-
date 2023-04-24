#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *makeNode(int x){
    node *temp = new node; // tạo mới một node
    temp->next = NULL; // node này chưa trỏ đến phần tử khác nên "next" nhận giá trị NULL
    temp->data = x;  // gán giá trị cho node
    return temp;
}
void printList(node *a){
	node *p = a;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}
node *addElement(node*p, int x){
	node *temp = makeNode(x); // Tạo 1 node mới có giá trị là x.
	p->next = temp; // Thêm node đó và cuối danh sách.
	return temp; // trả về node temp, vì temp giờ đã là node cuối của list.
}
int main()
{
   
    int n, x;
	cin >> n;
	cin >> x;
	node *a = makeNode(x);
	node *p = a;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	printList(a);
    return 0;
}