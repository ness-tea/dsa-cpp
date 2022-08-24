// Linked List implementation

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList(){}

template <typename T>
LinkedList<T>::~LinkedList()
{        
    while (m_head != nullptr)
    {
        DeleteNodeAtStart();
    }
}

template <typename T>
void LinkedList<T>::CreateNode(T Value)
{
    Node<T>* newNode = new Node(Value);
    newNode->Value = Value;
    newNode->Next = nullptr;

    if (m_head != nullptr)
    {
        m_tail->Next = newNode;
        m_tail = newNode;
    }
    else
    {
        m_head = newNode;
        m_tail = newNode;
    }

    newNode = nullptr;
}

template <typename T>
void LinkedList<T>::InsertNodeAtStart(T Value)
{
    Node<T>* newNode = new Node(Value);
    newNode->Value = Value;
    newNode->Next = m_head;
    m_head = newNode;
}

template <typename T>
void LinkedList<T>::InsertNodeAtEnd(T Value)
{
    Node<T>* newNode = new Node(Value);
    newNode->Value = Value;
    m_tail->Next = newNode;
    m_tail = newNode;
}

template <typename T>
void LinkedList<T>::InsertNodeAtPosition(T Value, int position)
{
    Node<T>* newNode = new Node(Value);
    Node<T>* prevNode = nullptr;
    Node<T>* curNode = m_head;

    for (int i = 0; i < position; i++)
    {
        prevNode = curNode;
        curNode = curNode->Next;
    }

    prevNode->Next = newNode;
    newNode->Next = curNode;
}

template <typename T>
void LinkedList<T>::DeleteNodeAtStart()
{
    Node<T>* oldHead = m_head;
    m_head = m_head->Next;
    delete oldHead;
}

template <typename T>
void LinkedList<T>::DeleteNodeAtEnd()
{
    Node<T>* oldTail = m_tail;
    Node<T>* curNode = m_head;

    while (curNode->Next != oldTail)
    {
        curNode = curNode->Next;
    }

    curNode->Next = nullptr;
    m_tail = curNode;
    delete oldTail;
}

template <typename T>
void LinkedList<T>::DeleteNodeAtPosition(int position)
{
    Node<T>* curNode = m_head;
    Node<T>* prevNode = nullptr;

    for (int i = 0; i < position; i++)
    {
        prevNode = curNode;
        curNode = curNode->Next;
    }

    prevNode->Next = curNode->Next;
    delete curNode;
}

template <typename T>
void LinkedList<T>::DisplayNodes()
{
    Node<T>* current = m_head;

    while (current != nullptr)
    {
        cout << current->Value << "\t";
        current = current->Next;
    }

    cout << endl;
}

int main()
{
    LinkedList<int> linkedList;
    int numNodes = 10;

    for (int i = 0; i < numNodes; i++)
    {
        linkedList.CreateNode(i);
    }

    // Test cases
    linkedList.DisplayNodes();

    linkedList.InsertNodeAtStart(11);
    linkedList.DisplayNodes();

    linkedList.InsertNodeAtEnd(31);
    linkedList.DisplayNodes();  

    linkedList.InsertNodeAtPosition(22, 3);
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtPosition(11);
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtStart();
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtEnd();
    linkedList.DisplayNodes();

    linkedList.DeleteNodeAtPosition(2);
    linkedList.DisplayNodes();

    linkedList.~LinkedList();

    return 0;
}