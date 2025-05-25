#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class LinkedList {
public:

    LinkedList() = default;

    LinkedList(const LinkedList& other);

    LinkedList(LinkedList&& other) noexcept;

    LinkedList& operator=(const LinkedList& other);

    LinkedList& operator=(LinkedList&& other) noexcept;

    ~LinkedList();

    bool insert(char* data, const size_t& dataLen);

    bool remove(char* data);

    bool search(char* data) const;

    size_t getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

private:
    struct Node {
        char* data;
        size_t dataLen;
        Node* nextNode;

        Node(char* data, const size_t& dataLen, Node* nextNode):
            data(data),
            dataLen(dataLen),
            nextNode(nextNode)
        { }

        Node(const Node& other) {
            dataLen = other.dataLen;
            data = new char[dataLen];
            for (int i = 0; i < dataLen; ++i) {
                data[i] = other.data[i];
            }
            nextNode = other.nextNode;
        }
    };

    Node* head_ = nullptr;
    size_t size_ = 0;

    void swap(LinkedList& other) noexcept;

    static int compare(const char* lhs, const char* rhs);
};



#endif //LINKED_LIST_H
