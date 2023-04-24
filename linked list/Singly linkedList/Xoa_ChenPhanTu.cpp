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
int size(Node *a)
{
    int count = 0;
    while (a != NULL)
    {
        ++count;
        a = a->next;
    }
    return count;
}
Node *addElement(Node *p, int x)
{
    Node *a = makeNode(x);
    p->next = a;
    return a;
}
Node *insertFirst(Node *a, int x)
{
    Node *temp = makeNode(x);
    temp->next = a;
    a = temp;
    return a;
}
Node *insertLast(Node *a, int x)
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
Node *insertMiddle(Node *a, int x, int k)
{
    if (k < -1 || k >= size(a))
    {
        cout << "Vi tri chen khong hop le\n";
    }
    if (k == 0)
    {
        insertFirst(a, x);
        return a;
    }
    if (k == size(a) - 1)
    {
        insertLast(a, x);

        return a;
    }
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
Node *deleteFirst(Node *a)
{
    Node *p = a;
    p = p->next;
}
Node *deleteLast(Node *a)
{
    Node *p = a;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
    return a;
}
Node *deleteMiddle(Node *a, int k)
{
    Node *p = a;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    Node *temp = p->next;
    p->next = p->next->next;
    delete temp;
    return a;
}
void sapxepTangdan(Node *a)
{
    Node *i, *j;
    int temp;
    for (i = a; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void sapxepGiamDan(Node *a)
{
    Node *i, *j;
    int temp;
    for (i = a; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data < j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
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
        cout << "---------7. Sap xep Tang Dan---\n";
        cout << "---------8. Sap xep Giam Dan---\n";
        cout << "---------9. In danh sach ------\n";
        cout << "-------------------------------\n";
        cout << "Nhap lua chon: \n";
        int choose;
        cin >> choose;
        if (choose == 1)
        {
            cout << "---------1. Chen dau ------------\n";
            cout << "Nhap x = \n";
            cin >> x;
            insertFirst(a, x);
        }
        else if (choose == 2)
        {
            cout << "---------2. Chen cuoi -----------\n";
            cout << "Nhap x = \n";
            cin >> x;
            insertLast(a, x);
        }
        else if (choose == 3)
        {
            cout << "---------3. Chen giua -----------\n";
            cout << "Nhap k = \n";
            cin >> k;
            cout << "Nhap x = \n";
            cin >> x;
            insertMiddle(a, x, k);
        }
        else if (choose == 4)
        {
            cout << "---------4. Xoa dau -----------\n";

            deleteFirst(a);
            cout << "da xoa dau";
        }
        else if (choose == 5)
        {
            cout << "---------5. Xoa cuoi -----------\n";

            deleteLast(a);
            cout << "da xoa cuoi";
        }
        else if (choose == 6)
        {
            cout << "---------6. Xoa giua -----------\n";
            cout << "Nhap k = \n";
            cin >> k;
            deleteMiddle(a, k);
        }
        else if (choose == 7)
        {
            cout << "---------7. Sap xep Tang Dan---\n";
            sapxepTangdan(a);
        }
        else if (choose == 8)
        {
            cout << "---------8. Sap xep Giam Dan---\n";
            sapxepGiamDan(a);
        }
        else if (choose == 9)
        {
            cout << "---------9. In danh sach ----\n";
            printList(a);
        }
    }
    return 0;
}
