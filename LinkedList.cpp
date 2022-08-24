// Linked List implementation (int type) 

#include <iostream>
using namespace std;

struct Node
{
    Node(int data)
    {
        Data = data;
    };

    int Data = 0;
    Node* Next = nullptr;
};

class LinkedList
{
private:
    Node* m_pHead = nullptr;
    Node* m_pTail = nullptr;

public:
    LinkedList(){};

    ~LinkedList()
    {        
        while (m_pHead != nullptr)
        {
            DeleteNodeAtStart();
        }
    };

    void CreateNode(int data)
    {
        Node* newNode = new Node(data);
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

    void InsertNodeAtStart(int data)
    {
        Node* newNode = new Node(data);
        newNode->Data = data;
        newNode->Next = m_pHead;
        m_pHead = newNode;
    }

    void InsertNodeAtEnd(int data)
    {
        Node* newNode = new Node(data);
        newNode->Data = data;
        m_pTail->Next = newNode;
        m_pTail = newNode;
    }

    void InsertNodeAtPosition(int data, int position)
    {
        Node* newNode = new Node(data);
        Node* prevNode = nullptr;
        Node* curNode = m_pHead;

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
        Node* oldHead = m_pHead;
        m_pHead = m_pHead->Next;
        delete oldHead;
    }

    void DeleteNodeAtEnd()
    {
        Node* oldTail = m_pTail;
        Node* curNode = m_pHead;

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
        Node* curNode = m_pHead;
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
        Node* current = m_pHead;

        while (current != nullptr)
        {
            cout << current->Data << "\t";
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