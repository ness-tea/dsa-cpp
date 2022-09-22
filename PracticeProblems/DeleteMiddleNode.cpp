#include "../LinkedList.hpp"
#include <iostream>
using namespace std;

void DeleteNode(Node<int>* pNode)
{
    if (pNode == nullptr || pNode->Next == nullptr)
    {
        return;
    }

    pNode->Data = pNode->Next->Data;
    pNode->Next = pNode->Next->Next;
}

int main()
{   
    LinkedList<int> linkedList = LinkedList<int>();
    int numNodes = 10;

    Node<int>* pNode = nullptr;

    for (int i = 0; i < numNodes; i++)
    {
        // delete node 5
        if (i == 5)
        {
            pNode = &linkedList.CreateNode(i);
        }
        else
        {
            linkedList.CreateNode(i);
        }

    }
    
    linkedList.DisplayNodes();

    DeleteNode(pNode);

    linkedList.DisplayNodes();

    return 0;
}