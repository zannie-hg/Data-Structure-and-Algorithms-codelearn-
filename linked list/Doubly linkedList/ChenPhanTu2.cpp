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
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void duyet(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int size(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        ++count;
        head = head->next;
    }
    return count;
}

void themdau(Node **head, int x)
{
    Node *newNode = makeNode(x);
    newNode->next = (*head);
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

void themcuoi(Node **head, int x)
{
    Node *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void themgiua(Node **head, int x, int k)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
    {
        cout << "Vi tri chen khong hop le\n";
        return;
    }
    if (k == 1)
    {
        themdau(head, x);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i <= k - 1; i++)
    {
        temp = temp->next;
    }
    Node *newNode = makeNode(x);
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}

Node *addElement(Node *head, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            head = makeNode(x);
        }
        else
        {
            themcuoi(&head, x);
        }
    }
    return head;
}

int main()
{
    int n, x, k;
    cin >> n;
    Node *head = addElement(NULL, n);
    duyet(head);
    cin >> k >> x;
    themgiua(&head, x, k);
    duyet(head);
    return 0;
}
