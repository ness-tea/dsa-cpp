// Linked List Template

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    Node(T data)
    {
        Data = data;
    };

    T Data;
    Node* Next = nullptr;
};

template <typename T>
class LinkedList
{
private:
    Node<T>* m_pHead = nullptr;
    Node<T>* m_pTail = nullptr;

public:
    LinkedList(){};
    ~LinkedList()
    {        
        while (m_pHead != nullptr)
        {
            DeleteNodeAtStart();
        }
    };

    void CreateNode(T data)
    {
        Node<T>* newNode = new Node(data);
        newNode->Data = data;
        newNode->Next = nullptr;

        if (m_pHead != nullptr)
        {
            m_pTail->Next = newNode;
            m_pTail = newNode;
        }
        else
        {
            m_pHead = newNode;
            m_pTail = newNode;
        }

        newNode = nullptr;
    }


    void InsertNodeAtStart(T data)
    {
        Node<T>* newNode = new Node(data);
        newNode->Data = data;
        newNode->Next = m_pHead;
        m_pHead = newNode;
    }

    void InsertNodeAtEnd(T data)
    {
        Node<T>* newNode = new Node(data);
        newNode->Data = data;
        m_pTail->Next = newNode;
        m_pTail = newNode;
    }

    void InsertNodeAtPosition(T data, int position)
    {
        Node<T>* newNode = new Node(data);
        Node<T>* prevNode = nullptr;
        Node<T>* curNode = m_pHead;

        for (int i = 0; i < position; i++)
        {
            prevNode = curNode;
            curNode = curNode->Next;
        }

        prevNode->Next = newNode;
        newNode->Next = curNode;
    }

    void DeleteNodeAtStart()
    {
        Node<T>* oldHead = m_pHead;
        m_pHead = m_pHead->Next;
        delete oldHead;
    }

    void DeleteNodeAtEnd()
    {
        Node<T>* oldTail = m_pTail;
        Node<T>* curNode = m_pHead;

        while (curNode->Next != oldTail)
        {
            curNode = curNode->Next;
        }

        curNode->Next = nullptr;
        m_pTail = curNode;
        delete oldTail;
    }

    void DeleteNodeAtPosition(int position)
    {
        Node<T>* curNode = m_pHead;
        Node<T>* prevNode = nullptr;

        for (int i = 0; i < position; i++)
        {
            prevNode = curNode;
            curNode = curNode->Next;
        }

        prevNode->Next = curNode->Next;
        delete curNode;
    }

    void DisplayNodes()
    {
        Node<T>* current = m_pHead;

        while (current != nullptr)
        {
            cout << current->Data << "\t";
            current = current->Next;
        }

        cout << endl;
    }

    friend class HashTable;
};