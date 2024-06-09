#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *ptr = nullptr;
};
struct List
{
    Node *h_node = nullptr;
};
void PushBack(List &list, const int &data)
{
    Node* n_node = new Node;
    n_node -> data = data;
    if (list.h_node == nullptr)
    {
        list.h_node = n_node;
    }
    else
    {
        Node* c_node = list.h_node;
        while (c_node -> ptr != nullptr)
        {
            c_node = c_node -> ptr;
        }
        c_node -> ptr = n_node;
    }
}
void PopFront(List& list)
{
    if (list.h_node == nullptr)
    {
        return;
    }
    Node *rem = list.h_node;
    list.h_node = list.h_node -> ptr;
    delete rem;
}
void PrintList(List &list, Node *c_node)
{
    while (c_node != nullptr)
    {
        cout << c_node -> data << ' ';
        c_node = c_node -> ptr;
    }
}
void Insert(List &list, char data, char x)
{
    Node* c_node = list.h_node;

    while (c_node != nullptr)
    {
        if (c_node -> data == data)
        {
            Node* n_node = new Node;
            n_node -> data = x;

            n_node -> ptr = c_node -> ptr;
            c_node -> ptr = n_node;
        } 
        c_node = c_node -> ptr;
    }
}
int main()
{
    List list;
    int size;
    int n;
    cout << "Enter the size of the list: " << endl;
    cin >> size;
    for (int i = 0; i != size; ++i)
    {
        PushBack(list, 65+i);
    }
    Node* c_node = list.h_node;
    PrintList(list, c_node);
    cout << endl << "Enter amount of elements to delete: " << endl;
    cin >> n;
    for (int i = 0; i != size-n; ++i)
    {
        PushBack(list, 65+i);
    }
    for (int i = 0; i != size; ++i)
    {
        PopFront(list);
    }
    c_node = list.h_node;
    PrintList(list, c_node);
    char k;
    char x = 88;
    cout << endl << "Enter the key: " << endl;
    cin >> k;
    bool flag = false;
    int count = 0;
    Insert(list, k, x);
    c_node = list.h_node;
    PrintList(list, c_node);
}