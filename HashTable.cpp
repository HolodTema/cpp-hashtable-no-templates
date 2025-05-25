#include "HashTable.h"

HashTable::HashTable(const size_t& size):
    size_(size)
{
    table_ = new LinkedList[size];
}

HashTable::~HashTable() {
    delete[] table_;
    table_ = nullptr;
}

bool HashTable::insert(char* key, const size_t& keyLen) {
    const bool isInserted = table_[hash(key)].insert(key, keyLen);
    return isInserted;
}

bool HashTable::remove(char* key) {
    const bool isRemoved = table_[hash(key)].remove(key);
    return isRemoved;
}

void HashTable::printCollisions(std::ostream& os, const unsigned int& hashValue) const {
    os << table_[hashValue] << '\n';
}

void HashTable::printCollisions(std::ostream& os) const {
    for (int i = 0; i < size_; ++i) {
        if (table_[i].getSize() > 1) {
            os << "Hash value = " << i << ": ";
            os << table_[i] << '\n';
        }
    }
}

unsigned int HashTable::hash(const char* str) const {
    unsigned int h = 0;
    while (*str) {
        h += *str++;
    }
    return h % size_;
}

std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {
    for (int i = 0; i < hashTable.size_; ++i) {
        os << hashTable.table_[i];
    }
    os << '\n';
    return os;
}