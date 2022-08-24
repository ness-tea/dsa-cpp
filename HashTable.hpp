// Hash Table implementation

#include "LinkedList.hpp"
#include <iostream>
using namespace std;

#define MAX_HASH_TABLE_SIZE 10

template <typename T_Key, typename T_Value>
struct HashEntry
{
    HashEntry(T_Key key, T_Value value)
    {
        Key = key;
        Value = value;
    }

    T_Key Key;
    T_Value Value;
};

template <typename T_Key, typename T_Value>
class HashTable
{
private:
    LinkedList<HashEntry<T_Key, T_Value>>* m_ht; // array of linked lists.
public:
    HashTable();
    ~HashTable();
};