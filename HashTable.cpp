// Hash Table implementation

#include "HashTable.hpp"
#include <iostream>

int main()
{
    HashTable hashTable = HashTable();

    // Test values
    hashTable.Insert(3, 3);
    hashTable.Insert(16, 6);
    hashTable.Insert(21, 1);
    hashTable.Insert(86, 8);

    hashTable.PrintHashTable();
    
    hashTable.~HashTable();

    return 0;
}