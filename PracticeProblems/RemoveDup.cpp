#include "../LinkedList.hpp"
#include <iostream>
using namespace std;

void RemoveDup(LinkedList<int>& linkedList)
{
    Node<int>* p1 = linkedList.m_pHead;
    Node<int>* p2 = p1->Next;
    Node<int>* prevp2 = p1;

    while (p1 != nullptr)
    {
        while (p2 != nullptr)
        {
            if (p1->Data == p2->Data)
            {
                Node<int>* dup = p2;
                p2 = p2->Next;
                prevp2->Next = p2;
                delete dup;
            }
            else
            {
                prevp2 = p2;
                p2 = p2->Next;
            }
        }

        if (p1->Next != nullptr)
        {
            p1 = p1->Next;
            p2 = p1->Next;
            prevp2 = p1;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    int numNodes = 10, data1 = 1, data2 = 3, data3 = 2;

    for (int i = 0; i < numNodes; i++)
    {
        linkedList.CreateNode(i);
    }

    linkedList.InsertNodeAtPosition(data1, 9);
    linkedList.InsertNodeAtPosition(data2, 7);
    linkedList.InsertNodeAtPosition(data3, 5);

    linkedList.DisplayNodes();

    RemoveDup(linkedList);

    linkedList.DisplayNodes();

    return 0;
}