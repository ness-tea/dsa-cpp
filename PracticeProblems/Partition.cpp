#include "../LinkedList.hpp"
#include <iostream>
using namespace std;

void Partition(LinkedList<int>& linkedList, int value)
{
    Node<int>* pHead = linkedList.m_pHead;
    Node<int>* pTail = linkedList.m_pTail;
    Node<int>* pPrev = linkedList.m_pHead;

    do
    {
        if (pHead->Data >= value)
        {
            if (pHead == linkedList.m_pHead)
            {
                linkedList.m_pHead = linkedList.m_pHead->Next;
                pTail->Next = pHead;
                pHead->Next = nullptr;
                pTail = pHead;

                pHead = linkedList.m_pHead;
            }
            else
            {
                Node<int>* pTemp = pHead;
                pPrev->Next = pHead->Next;
                pTail->Next = pTemp;
                pTemp->Next = nullptr;
                pTail = pTemp;

                pHead = pPrev->Next;
            }

            linkedList.DisplayNodes();
        }
        else
        {   
            pPrev = pHead;
            pHead = pHead->Next;

            linkedList.DisplayNodes();
        }
    } while (pHead != linkedList.m_pTail);
}

int main()
{
    LinkedList<int> linkedList = LinkedList<int>();

    int numNodes;
    cout << "Enter number of nodes to create in linked list: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++)
    {
        int value;
        cout << "Enter index " << i << ": ";
        cin >> value;

        linkedList.CreateNode(value);
    }

    int partition;
    cout << "Enter partitioin value: ";
    cin >> partition;

    linkedList.DisplayNodes();

    Partition(linkedList, partition);

    return 0;
}