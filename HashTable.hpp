// Hash Table implementation

#include <iostream>
using namespace std;

#define MAX_HASH_TABLE_SIZE 10

struct HashEntry
{
    HashEntry(int key, int value)
    {
        Key = key;
        Value = value;
    }

    int Key = 0;
    int Value;
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
    HashTable();
    HashTable(int size);
    ~HashTable();

    int Hash(int key);
    int Search(int key);
    void Insert(int key, int value);

    void Display();
};