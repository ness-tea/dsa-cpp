#include "LinkedList.hpp"
#include <iostream>
using namespace std;

#define MAX_SIZE_DEFAULT 10

struct HashEntry
{
    HashEntry(int key, int value)
    {
        Key = key;
        Value = value;
    }

    int Key = 0;
    int Value = 0;
};


template <typename T>
class LinkedList;
class HashTable
{
private:
    // Pointer to array of linked lists.
    LinkedList<HashEntry*>* m_pHT;
    int m_size;
    
public:
    HashTable() : m_size(MAX_SIZE_DEFAULT)
    {
        m_pHT = new LinkedList<HashEntry*>[MAX_SIZE_DEFAULT];
    }

    HashTable(int size) : m_size(size)
    {
        m_pHT = new LinkedList<HashEntry*>[size];
    }

    ~HashTable()
    {
        for (int i = 0; i < m_size; i++)
        {
            m_pHT[i].~LinkedList();

        }
    }

    int Hash(int key)
    {
        return key % m_size;
    }

    int Search(int key)
    {
        int retValue;
        LinkedList<HashEntry*> linkedList = m_pHT[Hash(key)];
        
        while (linkedList.m_pHead != nullptr)
        {
            if (linkedList.m_pHead->Data->Key == key)
            {
                retValue = linkedList.m_pHead->Data->Value;
            }
        }

        return retValue;
    }

    void Insert(int key, int value)
    {
        HashEntry* newEntry = new HashEntry(key, value);
        m_pHT[Hash(key)].CreateNode(newEntry);
    }

    LinkedList<HashEntry*>* GetListForHashIndex(int index)
    {
        return &m_pHT[index];
    }

    void PrintHashTable()
    {
        for (int i = 0; i < m_size; i++)
        {
            LinkedList<HashEntry*>* pList = GetListForHashIndex(i);
            Node<HashEntry*>* curNode = pList->m_pHead;

            while (curNode != nullptr)
            {
                cout << "(" << curNode->Data->Key << ", " << curNode->Data->Value << ") - ";
                curNode = curNode->Next;
            }

            cout << endl;
        }
    }
};