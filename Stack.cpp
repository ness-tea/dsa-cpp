#include <iostream>

using namespace std;

template <typename T>
class Stack
{
public:
    struct Node
    {
        Node(T data)
        {
            this->Data = data;
        };

        T Data = 0;
        Node* Next = nullptr;
    };

    Node* m_pTop = nullptr;

    Stack(T data)
    {
        Node* pTemp = new Node(data);

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
            Node* pTemp = m_pTop;
            m_pTop = m_pTop->Next;
            delete pTemp;
        }
    };

    void Push(T data)
    {
        Node* pNewNode = new Node(data);
        pNewNode->Next = m_pTop;
        m_pTop = pNewNode;
    };

    Node* Pop()
    {
        Node* pTemp = m_pTop;

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
};

int main()
{
    return 0;
}