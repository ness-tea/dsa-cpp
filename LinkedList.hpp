// Linked List implementation

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    Node(T value)
    {
        Value = value;
    };

    T Value;
    Node* Next = nullptr;
};

template <typename T>
class LinkedList
{
private:
    Node<T>* m_head = nullptr;
    Node<T>* m_tail = nullptr;

public:
    LinkedList();
    ~LinkedList();

    void CreateNode(T Value);

    void InsertNodeAtStart(T Value);

    void InsertNodeAtEnd(T Value);

    void InsertNodeAtPosition(T Value, int position);

    void DeleteNodeAtStart();

    void DeleteNodeAtEnd();

    void DeleteNodeAtPosition(int position);

    void DisplayNodes();
};