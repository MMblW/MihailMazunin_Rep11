#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node* n_ptr;
};
struct Stack
{
    Node *head = nullptr;
    int size = 0;
};
void SetNode(Node*&node, char data, Node* n_ptr = nullptr)
{
    node = new Node;
    node -> n_ptr = n_ptr;
    node -> data = data;
}
void Push(Stack &tmp, const char &data)
{
    Node* n_node;
    SetNode(n_node, data, tmp.head);
    tmp.head = n_node;
    tmp.size++;
}
void Pop(Stack &tmp)
{
    if (tmp.head != nullptr)
    {
        Node *delete_element = tmp.head;
        tmp.head = tmp.head -> n_ptr;
        delete delete_element;
        tmp.size--;
    }
}
int main()
{
    int size, n;
    Stack stack;
    Stack tempstack;
    cout << "Enter size of the stack: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        Push(stack, 65+i);
        cout << stack.head -> data << " ";
    }
    cout << endl << "Enter amount of elements to delete: " << endl;
    cin >> n;
    for (int i = 0; i < size; i++)
    {
        Push(tempstack, stack.head -> data);
        Pop(stack);
    }
    for (int i = 0; i < size - n; i++)
    {
        Push(stack, tempstack.head -> data);
        cout << tempstack.head -> data << " ";
        Pop(tempstack);
    }
    for (int i = 0; i < n; i++)
    {
        Pop(tempstack);
    }
    char k;
    char x = 88;
    cout << endl << "Enter the key: " << endl;
    cin >> k;
    for (int i = 0; i < size-n; i++)
    {
        if (stack.head -> data == k)
        {
            Push(tempstack, x);
        }
        Push(tempstack, stack.head -> data);
        Pop(stack);
    }
    for (int i = 0; i < size-n+1; i++)
    {
        Push(stack, tempstack.head -> data);
        cout << tempstack.head -> data << " ";
        Pop(tempstack);
    }
}