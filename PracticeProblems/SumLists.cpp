#include "../LinkedList.hpp"
#include <iostream>

using namespace std;

LinkedList<int> SumLists(LinkedList<int> l1, LinkedList<int> l2)
{   
    LinkedList<int> result = LinkedList<int>();
    
    Node<int>* pL1 = l1.m_pHead;
    Node<int>* pL2 = l2.m_pHead;

    int remainder = 0;

    while (pL1 != nullptr || pL2 != nullptr)
    {
        int sum = 0;
        
        if (pL1 != nullptr) sum += pL1->Data;
        if (pL2 != nullptr) sum += pL2->Data;

        sum += remainder;
        remainder = 0;

        while (sum > 10)
        {
            sum -= 10;
            remainder++;
        }

        result.CreateNode(sum);

        if (pL1 != nullptr) pL1 = pL1->Next;
        if (pL2 != nullptr) pL2 = pL2->Next;
    }
    
    return result;
}

int main()
{
    LinkedList<int> l1 = LinkedList<int>();
    LinkedList<int> l2 = LinkedList<int>();

    int numNodesl1, numNodesl2;
    cout << "Enter number of nodes in list 1: ";
    cin >> numNodesl1;

    cout << "Enter number of nodes in list 2: ";
    cin >> numNodesl2;

    for (int i = 0; i < numNodesl1; i++)
    {
        int value;
        cout << "Enter value for list 1 entry " << i << ": ";
        cin >> value;
        l1.CreateNode(value);
    }

    for (int i = 0; i < numNodesl2; i++)
    {
        int value;
        cout << "Enter value for list 2 entry " << i << ": ";
        cin >> value;
        l2.CreateNode(value);
    }
    
    l1.DisplayNodes();
    l2.DisplayNodes();

    LinkedList<int> result = SumLists(l1, l2);

    result.DisplayNodes();

    return 0;
}