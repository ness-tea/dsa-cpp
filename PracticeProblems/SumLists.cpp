#include "../LinkedList.hpp"
#include <iostream>

using namespace std;

LinkedList<int> SumLists(LinkedList<int> l1, LinkedList<int> l2)
{   
    LinkedList<int> result = LinkedList<int>();
    
    Node<int>* pL1 = l1.m_pHead;
    Node<int>* pL2 = l2.m_pHead;

    l1.DisplayNodes();
    l2.DisplayNodes();

    int remainder = 0;

    while (pL1 != nullptr || pL2 != nullptr)
    {
        int sum = 0;
        
        if (pL1 != nullptr) sum += pL1->Data;
        if (pL2 != nullptr) sum += pL2->Data;

        sum += remainder;
        remainder = 0;

        while (sum >= 10)
        {
            sum %= 10;
            remainder++;
        }

        result.CreateNode(sum);

        if (pL1 != nullptr) pL1 = pL1->Next;
        if (pL2 != nullptr) pL2 = pL2->Next;
    }

    if (remainder > 0)
    {
        result.CreateNode(remainder);
    }
    
    return result;
}

int AddListDigits(Node<int>* pL1, Node<int>* pL2, LinkedList<int>& result)
{
    int carry = 0;

    int sum = 0;

    if (pL1 != nullptr) sum += pL1->Data;
    if (pL2 != nullptr) sum += pL2->Data;

    if (pL1->Next == nullptr && pL2->Next == nullptr)
    {
        if (sum >= 10)
        {
            sum %= 10;
            carry++;
        }

        result.CreateNode(sum);
    }
    else
    {
        int remainder = AddListDigits(pL1->Next, pL2->Next, result);
        sum += remainder;

        while (sum >= 10)
        {
            sum %= 10;
            carry++;
        }

        result.InsertNodeAtStart(sum);
    }

    return carry;
}



// Digits stored in forward order
LinkedList<int> SumLists2(LinkedList<int> l1, LinkedList<int> l2)
{   
    LinkedList<int> result = LinkedList<int>();
    
    Node<int>* pL1 = l1.m_pHead;
    Node<int>* pL2 = l2.m_pHead;

    int length1 = 0, length2 = 0;

    while (pL1 != nullptr)
    {
        length1++;
        pL1 = pL1->Next;
    }

    while (pL2 != nullptr)
    {
        length2++;
        pL2 = pL2->Next;
    }

    if (length1 > length2)
    {
        for (int i = 0; i < (length1 - length2); i++)
        {
            int data = 0;
            l2.InsertNodeAtStart(data);
        }
    }
    else
    {
        for (int i = 0; i < (length2 - length1); i++)
        {
            int data = 0;
            l1.InsertNodeAtStart(data);
        }
    }

    l1.DisplayNodes();
    l2.DisplayNodes();

    pL1 = l1.m_pHead;
    pL2 = l2.m_pHead;

    AddListDigits(pL1, pL2, result);

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
        cout << "Enter single-digit value for list 1 entry " << i << ": ";
        cin >> value;
        l1.CreateNode(value);
    }

    for (int i = 0; i < numNodesl2; i++)
    {
        int value;
        cout << "Enter single-digit value for list 2 entry " << i << ": ";
        cin >> value;
        l2.CreateNode(value);
    }

    LinkedList<int> result = SumLists(l1, l2);

    result.DisplayNodes();

    return 0;
}