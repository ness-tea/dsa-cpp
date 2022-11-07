#include "../Stack.hpp"
#include <iostream>

using namespace std;

class StackWithMin : public Stack<int>
{
public:
    Stack<int> min;

    void Push(int data)
    {
        if (Stack<int>::m_pTop == nullptr || (Stack<int>::m_pTop != nullptr && Stack<int>::m_pTop->Data >= data))
        {
            min.Push(data);
        }

        Node<int>* pNewNode = new Node<int>(data);
        pNewNode->Next = Stack<int>::m_pTop;
        Stack<int>::m_pTop = pNewNode;
    };

    Node<int>* Pop()
    {
        Node<int>* pTemp = m_pTop;

        if (m_pTop != nullptr)
        {
            if (m_pTop->Data == min.m_pTop->Data)
            {
                min.Pop();
            }

            m_pTop = m_pTop->Next;
        }

        return pTemp;
    };
};