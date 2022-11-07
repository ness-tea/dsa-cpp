#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    Node(T data)
    {
        this->Data = data;
    };

    T Data = 0;
    Node* Next = nullptr;
};

template <typename T>
class Stack
{
public:
    Node<T>* m_pTop = nullptr;

    Stack(){};
    Stack(T data)
    {
        Node<T>* pTemp = new Node(data);

        if (m_pTop == nullptr)
        {
            m_pTop = pTemp;
        }
        else
        {
            pTemp->Next = m_pTop;
            m_pTop = pTemp;
        }
    };

    ~Stack()
    {
        while (m_pTop != nullptr)
        {
            Node<T>* pTemp = m_pTop;
            m_pTop = m_pTop->Next;
            delete pTemp;
        }
    };

    void Push(T data)
    {
        Node<T>* pNewNode = new Node(data);
        pNewNode->Next = m_pTop;
        m_pTop = pNewNode;
    };

    Node<T>* Pop()
    {
        Node<T>* pTemp = m_pTop;

        if (m_pTop != nullptr)
        {
            m_pTop = m_pTop->Next;
        }

        return pTemp;
    };

    int Peek()
    {
        return (m_pTop != nullptr ? m_pTop->Data : 0);
    };

    bool IsEmpty()
    {
        return (m_pTop == nullptr);
    };

    void DisplayStackNodes()
    {
        Node<T>* pTemp = m_pTop;
        cout << "Top" << endl;
        while (pTemp != nullptr)
        {
            cout << pTemp->Data << endl;
            pTemp = pTemp->Next;
        }

        cout << "Bottom" << endl;
    }
};