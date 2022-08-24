// Hash Table implementation

#include "HashTable.hpp"
#include "LinkedListTemplate.hpp"

HashTable::HashTable()
{
    m_pHT = new LinkedList<HashEntry>[MAX_HASH_TABLE_SIZE];
}

HashTable::HashTable(int size) : m_size(size)
{
    m_pHT = new LinkedList<HashEntry>[size];
}

HashTable::~HashTable(){}

int HashTable::Hash(int key)
{
    return key % m_size;
}

int HashTable::Search(int key)
{
    int retValue;
    LinkedList linkedList = m_pHT[Hash(key)];
    
    while (linkedList.m_pHead != nullptr)
    {
        if (linkedList.m_pHead->Data.Key == key)
        {
            retValue = linkedList.m_pHead->Data.Value;
        }
    }

    return retValue;
}

void HashTable::Insert(int key, int value)
{

}

int main()
{
    return 0;
}