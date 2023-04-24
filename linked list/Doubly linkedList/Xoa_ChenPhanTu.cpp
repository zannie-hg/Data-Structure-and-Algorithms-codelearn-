#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *makeNode(int x)
{
    Node *a = new Node;
    a->data = x;
    a->next = NULL;
    a->prev = NULL;
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
int size(Node *a)
{

    int count = 0;
    while (a != NULL)
    {
        ++count;
        a = a->next; // gan dia chi cua node tiep theo cho node hien tai
        // cho node hien tai nhay sang node tiep theo
    }
    return count;
}
Node *addElement(Node *p, int x)
{
    Node *temp = makeNode(x);
    p->next = temp;
    temp->prev = p;
    return temp;
}
Node *insertFirst(Node **a, int x)
{
    Node *p = makeNode(x);
    p->next = *a;
    (*a)->prev = p;
    (*a) = p;
    return *a;
}
Node *insertLast(Node **a, int x)
{
    Node *p = *a;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *temp = makeNode(x);
    temp->prev = p;
    temp->next = NULL;
    p->next = temp;
    return *a;
}
Node *insertMiddle(Node **a, int x, int k)
{

    if (k < -1 || k >= size(*a))
    {
        cout << "Vi tri chen khong hop le" << endl;
    }
    if (k == 0)
    {
        insertFirst(a, x);
        return *a;
    }
    if (k == size(*a) - 1)
    {
        insertLast(a, x);
        return *a;
    }
    Node *p = *a;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    Node *temp = makeNode(x);
    temp->prev = p;
    temp->next = p->next;
    p->next->prev = temp;
    p->next = temp;
    return *a;
}
Node *deleteFirst(Node **a, int x)
{
    Node *p = *a;
    *a = p->next;
    (*a)->prev = NULL;
    delete p;
    return *a;
}
Node *deleteLast(Node **a, int x)
{
    Node *p = *a;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
    delete p;
    return *a;
}
Node *deleteMiddle(Node **a, int k)
{
     if (k < -1 || k >= size(*a))
    {
        cout << "Vi tri xoa khong hop le" << endl;
    }
    Node *p = *a;
    for (int i = 0; i <= k - 1; i++)
    {
        p = p->next;
    }
    p->prev->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }
    delete p;
   
    return *a;
   
}
int main()
{
    int n, x, k;
    cout << "Nhap kich thuoc: \n";
    cin >> n;
    cout << "Nhap phan tu: \n";
    cin >> x;
    Node *a = makeNode(x);
    Node *p = a;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    while (1)
    {
        cout << endl;
        cout << "-------------MENU--------------\n";
        cout << "---------1. Chen dau ----------\n";
        cout << "---------2. Chen cuoi ---------\n";
        cout << "---------3. Chen giua ---------\n";
        cout << "---------4. Xoa dau -----------\n";
        cout << "---------5. Xoa cuoi ----------\n";
        cout << "---------6. Xoa giua ----------\n";

        cout << "---------7. In danh sach ------\n";
        cout << "-------------------------------\n";
        cout << "Nhap lua chon: \n";
        int choose;
        cin >> choose;
        if (choose == 1)
        {
            cout << "---------1. Chen dau ------------\n";
            cout << "Nhap x = \n";
            cin >> x;
            insertFirst(&a, x);
        }
        else if (choose == 2)
        {
            cout << "---------2. Chen cuoi -----------\n";
            cout << "Nhap x = \n";
            cin >> x;
            insertLast(&a, x);
        }
        else if (choose == 3)
        {
            cout << "---------3. Chen giua -----------\n";
            cout << "Nhap k = \n";
            cin >> k;
            cout << "Nhap x = \n";
            cin >> x;
            insertMiddle(&a, x, k);
        }
        else if (choose == 4)
        {
            cout << "---------4. Xoa dau -----------\n";

            deleteFirst(&a, x);
        }
        else if (choose == 5)
        {
            cout << "---------5. Xoa cuoi -----------\n";

            deleteLast(&a, x);
        }
        else if (choose == 6)
        {
            cout << "---------6. Xoa giua -----------\n";
            cout << "Nhap k = \n";
            cin >> k;
            deleteMiddle(&a, k);
        }
        else if (choose == 7)
        {
            cout << "---------3. In danh sach ----\n";
            printList(a);
        }
    }
    return 0;
}
