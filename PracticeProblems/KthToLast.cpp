#include "../LinkedList.hpp"
#include <iostream>
using namespace std;

int GetKthToLastElement(int k, LinkedList<int>& linkedList)
{
    Node<int>* p1 = linkedList.m_pHead;
    Node<int>* p2 = p1;

    int counter = 0;
    while (counter < k && p2 != nullptr)
    {
        p2 = p2->Next;
        counter++;
    }

    while (p2 != nullptr && p2->Next != nullptr)
    {
        p1 = p1->Next;
        p2 = p2->Next;
    }

    if (counter < k || p1 == nullptr)
    {
        return 0;
    }

    return p1->Data;
}


int main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    int numNodes = 10, data1 = 1, data2 = 3, data3 = 2;

    for (int i = 0; i < numNodes; i++)
    {
        linkedList.CreateNode(i);
    }

    linkedList.DisplayNodes();

    int k;
    cout << "Enter k to last element to return: ";
    cin >> k;

    cout << "Kth to last element in list is " << GetKthToLastElement(k, linkedList) << endl;

    return 0;
}