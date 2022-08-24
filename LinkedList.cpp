// Linked List 

#include <iostream>
using namespace std;

struct Node
{
    Node(int value)
    {
        Value = value;
    };

    int Value = 0;
    Node* Next = nullptr;
};

class LinkedList
{
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;

public:
    LinkedList(){};
    ~LinkedList()
    {        
        while (m_head != nullptr)
        {
            DeleteNodeAtStart();
        }
    };

    void CreateNode(int Value)
    {
        Node* newNode = new Node(Value);
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

    void InsertNodeAtStart(int Value)
    {
        Node* newNode = new Node(Value);
        newNode->Value = Value;
        newNode->Next = m_head;
        m_head = newNode;
    }

    void InsertNodeAtEnd(int Value)
    {
        Node* newNode = new Node(Value);
        newNode->Value = Value;
        m_tail->Next = newNode;
        m_tail = newNode;
    }

    void InsertNodeAtPosition(int Value, int position)
    {
        Node* newNode = new Node(Value);
        Node* prevNode = nullptr;
        Node* curNode = m_head;

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
        Node* oldHead = m_head;
        m_head = m_head->Next;
        delete oldHead;
    }

    void DeleteNodeAtEnd()
    {
        Node* oldTail = m_tail;
        Node* curNode = m_head;

        while (curNode->Next != oldTail)
        {
            curNode = curNode->Next;
        }

        curNode->Next = nullptr;
        m_tail = curNode;
        delete oldTail;
    }

    void DeleteNodeAtPosition(int position)
    {
        Node* curNode = m_head;
        Node* prevNode = nullptr;

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
        Node* current = m_head;

        while (current != nullptr)
        {
            cout << current->Value << "\t";
            current = current->Next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList linkedList = LinkedList();
    int numNodes = 10;

    for (int i = 0; i < numNodes; i++)
    {
        linkedList.CreateNode(i);
    }

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