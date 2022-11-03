#include "../LinkedList.hpp"
#include <iostream>

using namespace std;

// Detects if loop exists in linked list, and returns first node in loop
Node<int>* LoopDetection(LinkedList<int>& linkedList)
{
    Node<int>* p1 = linkedList.m_pHead;
    Node<int>* p2 = linkedList.m_pHead->Next;

    bool found = false;
    while (p1 != nullptr)
    {
        if (p1 == p2)
        {
            found = true;
            break;
        }

        p1 = p1->Next;
        p2 = p2->Next->Next;
    }

    if (found)
    {
        p1 = linkedList.m_pHead;

        while (p1 != p2)
        {
            p1 = p1->Next;
            p2 = p2->Next;
        }
    }
    
    return (found ? p1 : nullptr);
}

int main()
{
    return 0;
}   