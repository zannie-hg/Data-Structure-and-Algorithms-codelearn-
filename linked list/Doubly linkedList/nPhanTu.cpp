#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* makeNode(int x) {
    node* temp = new node;
    temp->next = nullptr;
    temp->prev = nullptr;
    temp->data = x;
    return temp;
}

void printList(node* a) {
    node* p = a;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}

node* addElement(node* p, int x) {
    node* temp = makeNode(x);
    temp->prev = p;
    p->next = temp;
    return temp;
}

int main() {
    int n, x;
    cin >> n >> x;
    node* a = makeNode(x);
    node* p = a;
    for (int i = 1; i < n; i++) {
        cin >> x;
        p = addElement(p, x);
    }
    printList(a);
    return 0;
}
