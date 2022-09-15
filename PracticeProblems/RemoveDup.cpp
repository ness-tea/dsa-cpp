#include "../LinkedList.hpp"
#include <iostream>
using namespace std;

void RemoveDup(LinkedList<int>& linkedList)
{
    Node<int>* p1 = linkedList.m_pHead;

    while (p1 != nullptr)
    {
        Node<int>* p2 = p1;

        while (p2->Next != nullptr)
        {
            if (p1->Data == p2->Next->Data)
            {
                Node<int>* dup = p2->Next;
                p2->Next = p2->Next->Next;
                delete dup;
            }
            else
            {
                p2 = p2->Next;
            }
        }

        p1 = p1->Next;
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