#include <iostream>

using namespace std;

template <typename T>
class Queue
{
public:
    struct Node
    {
        Node(T data)
        {
            this->Data = data;
        };

        T Data;
        Node* Next = nullptr;
    };

    Node* m_pFirst = nullptr;
    Node* m_pLast = nullptr;

    Queue(T data)
    {
        m_pLast = new Node(data);
        m_pFirst = m_pLast;
    };

    ~Queue()
    {
        while (m_pFirst != nullptr)
        {
            Node* pTemp = m_pFirst;
            m_pFirst = m_pFirst->Next;
            delete pTemp;
        }
    };

    void Add(T data)
    {
        Node* pNewNode = new Node(data);

        if (m_pLast == m_pFirst)
        {
            m_pFirst->Next = pNewNode;
        }
                m_pLast->Next = pNewNode;
        m_pLast->Next = pNewNode;
        m_pLast = pNewNode;
    };

    Node* Remove()
    {
        Node* pTemp = m_pFirst;
        m_pFirst = m_pFirst->Next;

        return pTemp;
    };

    T Peek()
    {
        return (m_pFirst != nullptr ? m_pFirst->Data : 0);
    }

    bool IsEmpty()
    {
        return (m_pFirst == nullptr && m_pLast == nullptr);
    }
};

int main()
{
    Queue queue = new Queue(1);
    
    return 0;
}