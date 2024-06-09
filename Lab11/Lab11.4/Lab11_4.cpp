#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node* n_ptr;
};
struct Q
{
    Node *head;
    Node *tail;
    int size;
};
void InitQ(Q &q, const char &data)
{
    Node *n_node = new Node;
    n_node -> data = data;
    q.head = n_node;
    q.tail = n_node;
    q.size = 1;
}
void Push(Q &q, const char &data)
{
    Node* n_node = new Node;
    q.size++;
    n_node -> data = data;
    n_node -> n_ptr = n_node;
    q.tail -> n_ptr = n_node;
    q.tail = n_node;
}
void NewQ(Q &q, int n)
{
    InitQ(q, 65);
    std::cout << q.tail -> data << " ";
    for (int i = 1; i < n; i++)
    {
        Push(q, 65+i);
        cout << q.tail -> data << " ";
    }
}
void Pop(Q &q)
{
    Node *tmp = q.head;
    q.head = q.head -> n_ptr;
    q.size--;
    delete tmp;
}
int main()
{
    int size, n;
    Q q;
    Q tempq;
    cout << "Enter size of the queue: " << endl;
    cin >> size;
    InitQ(q, 65);
    NewQ(q, size);
    cout << endl << "Enter amount of elements to delete: " << endl;
    cin >> n;
    for (int i = 0; i < size - n; i++)
    {
        Push(q, q.head -> data);
        Pop(q);
        std::cout << q.tail -> data << " ";
    }
    for (int i = 0; i < n; i++)
    {
        Pop(q);
    }
    char k;
    char x = 88;
    cout << endl << "Enter the key: " << endl;
    cin >> k;
    for (int i = 0; i < size - n; i++)
    {
        Push(q, q.head -> data);
        cout << q.tail -> data << " ";
        Pop(q);
        if (q.tail -> data == k)
        {
            Push(q, x);
            cout << q.tail -> data << " ";
        }
    }
}