#include "../LinkedList.hpp"
#include <iostream>

using namespace std;

bool CompareListData(Node<int>* pHead, Node<int>* pTail)
{
    bool isEqual = false;

    if (pHead != nullptr && pTail != nullptr)
    {
        if (pTail->Next == nullptr)
        {
            if (pHead->Data == pTail->Data)
            {
                isEqual = true;
            }
        }
        else
        {
            isEqual = CompareListData(pHead, pTail->Next);

            if (isEqual)
            {
                pHead = pHead->Next;

                if (pHead != nullptr)
                {
                    if (pHead->Data == pTail->Data)
                    {
                        isEqual = true;
                    }
                }
            }
        }
    }

    return isEqual;
}

bool IsLinkedListPalindrome(LinkedList<int>& list)
{
    bool isPalindrome = false;

    isPalindrome = CompareListData(list.m_pHead, list.m_pHead);

    return isPalindrome;
}

int main()
{
    LinkedList<int> list = LinkedList<int>();

    int numNodes;
    cout << "Enter number of nodes in list: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++)
    {
        int value;
        cout << "Enter value for list entry " << i << ": ";
        cin >> value;
        list.CreateNode(value);
    }

    list.DisplayNodes(); 
    cout << endl;

    cout << "Is list a palindrome? : " << IsLinkedListPalindrome(list) << endl;

    return 0;
}