#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
typedef struct Node *node;

// cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}
// kiem tra rong
bool empty(node a)
{
    return a == NULL;
}
int size(node a)
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
// them mot phan tu vao dau danh sach lien ket
void insertFirst(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        tmp->next = a;
        a = tmp;
    }
}
// them phan tu vao cuoi danh sach
void insertLast(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        node p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}
// them mot phan tu vao giua
void insertMiddle(node &a, int x, int pos)
{
    int n = size(a);
    if (pos <= 0 || pos > n + 1)
    {
        cout << "Vi tri chen khong hop le" << endl;
    }
    if (pos == 1)
    {
        insertFirst(a, x);
        return;
    }
    if (pos == n + 1)
    {
        insertLast(a, x);
        return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}
// xoa phan tu o dau
void deleteFirst(node &a)
{
    if (a == NULL)
    {
        return;
    }
    a = a->next;
}

// xoa phan tu o cuoi
void deleteLast(node &a)
{
     if(a == NULL)
        return;
    if(a->next == NULL){ // Trường hợp danh sách chỉ có một nút
        a = NULL;
        delete a;
        return;
    }
    node temp = a;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next=NULL;
    cout<<"da xoa\n";
}
void deleteMiddle(node &a, int pos)
{
    int n = size(a);

    if (pos <= 0 || pos > n+1)
    {
         cout<<"vi tri xoa khong hop le !\n";
        return;
    }
    if (pos == 1)
    {
        deleteFirst(a);
        return;
    }
    if (pos == n)
    {
        deleteLast(a);
        return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    node q = p->next;
    p->next = q->next;
    delete q;
}
void print(node a)
{
    cout << "-----------------------------------\n";
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "-----------------------------------\n";
}
// void sapxep(node )
int main()
{
    node head = nullptr;
    while (1)
    {
        cout << "----------------------MENU------------------------\n";

        cout << "1. Chen phan tu vao dau\n";
        cout << "2. Chen phan tu vao cuoi\n";
        cout << "3. Chen phan tu vao giua\n";
        cout << "4. Xoa phan tu o dau \n";
        cout << "5. Xoa phan tu o cuoi \n";
        cout << "6. Xoa phan tu o giua\n";
        cout << "7. Duyet dslk\n";
        cout << "--------------------------------------------------\n";
        cout << "Nhap lua chon:";
        int choose;
        cin >> choose;
      if(choose == 1){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			insertFirst(head, x);
		}
		else if(choose == 2){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			insertLast(head, x);
		}
		else if(choose == 3){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(head, x, pos);
		}
		else if(choose == 4){
			deleteFirst(head);
		}
		else if(choose == 5){
			deleteLast(head);
		}
		else if(choose == 6){
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if(choose == 7){
			print(head);
		}
    }

    return 0;
}