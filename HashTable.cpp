// Hash Table implementation

#include "LinkedListTemplate.hpp"
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
    LinkedList<HashEntry>* m_pHT;
    int m_size;
    
public:
    HashTable() : m_size(MAX_SIZE_DEFAULT)
    {
        m_pHT = new LinkedList<HashEntry>[MAX_SIZE_DEFAULT];
    }

    HashTable(int size) : m_size(size)
    {
        m_pHT = new LinkedList<HashEntry>[size];
    }

    ~HashTable(){}

    int Hash(int key)
    {
        return key % m_size;
    }

    int Search(int key)
    {
        int retValue;
        LinkedList linkedList = m_pHT[Hash(key)];
        
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

    LinkedList<HashEntry> GetListForHashIndex(int index)
    {
        return m_pHT[index];
    }

    void PrintHashTable()
    {
        for (int i = 0; i < m_size; i++)
        {
            LinkedList<HashEntry> list = GetListForHashIndex(i);
            Node<HashEntry>* curNode = list.m_pHead;

            while (curNode != nullptr)
            {
                cout << "(" << curNode->Data->Key << ", " << curNode->Data->Value << ")" << "\t";
                curNode = curNode->Next;
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable hashTable = HashTable();

    // Test values
    HashEntry entry1 = HashEntry(3, 3);
    HashEntry entry2 = HashEntry(16, 6);
    HashEntry entry3 = HashEntry(21, 1);
    HashEntry entry4 = HashEntry(86, 8);

    hashTable.Insert(entry1.Key, entry1.Value);
    hashTable.Insert(entry2.Key, entry2.Value);
    hashTable.Insert(entry3.Key, entry3.Value);
    hashTable.Insert(entry4.Key, entry4.Value);

    hashTable.PrintHashTable();

    return 0;
}