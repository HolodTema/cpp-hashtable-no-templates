#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include "LinkedList.h"

class HashTable {
public:

    explicit HashTable(const size_t& size);

    HashTable(const HashTable& other) = delete;

    HashTable(const HashTable&& other) = delete;

    HashTable& operator=(const HashTable& other) = delete;

    HashTable& operator=(const HashTable&& other) = delete;

    ~HashTable();

    bool insert(char* key, const size_t& keyLen);

    bool remove(char* key);

    void printCollisions(std::ostream& os, const unsigned int& hashValue) const;

    void printCollisions(std::ostream& os) const;

    unsigned int hash(const char* str) const;

    friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);

private:
    size_t size_;
    LinkedList* table_;
};

#endif //HASH_TABLE_H
