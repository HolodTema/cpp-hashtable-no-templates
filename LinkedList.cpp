#include <string>
#include "LinkedList.h"


LinkedList::LinkedList(const LinkedList& other) {
    Node* node = other.head_;
    while (node != nullptr) {
        head_ = new Node(*node);
        node = node->nextNode;
    }
}

LinkedList::LinkedList(LinkedList&& other) noexcept {
    swap(other);
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        LinkedList otherCopy(other);
        swap(otherCopy);
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    swap(other);
}

LinkedList::~LinkedList() {
    Node* node = head_;
    while (node != nullptr) {
        Node* nextNode = node->nextNode;
        delete node;
        node = nextNode;
    }
}

bool LinkedList::insert(char* data, const size_t& dataLen) {
    if (head_ == nullptr) {
        head_ = new Node(data, dataLen, nullptr);
        return true;
    }

    Node* prevNode = nullptr;
    Node* node = head_;
    while (node != nullptr) {
        const int compareResult = compare(node->data, data);
        if (compareResult == 0) {
            return false;
        }
        if (compareResult < 0) {
            if (prevNode == nullptr) {
                prevNode = new Node(data, dataLen, node);
                return true;
            }
            prevNode->nextNode = new Node(data, dataLen, node);
            return true;
        }
        prevNode = node;
        node = node->nextNode;
    }
    return false;
}

bool LinkedList::remove(char* data) {
    Node* node = head_;
    Node* prevNode = nullptr;
    while (node != nullptr) {
        if (compare(node->data, data) == 0) {
            if (prevNode != nullptr) {
                prevNode->nextNode = node->nextNode;
            }
            delete node;
            return true;
        }
        prevNode = node;
        node = node->nextNode;
    }
    return false;
}

bool LinkedList::search(char* data) const {
    Node* node = head_;
    while (node != nullptr) {
        if (compare(node->data, data) == 0) {
            return true;
        }
        node = node->nextNode;
    }
    return false;
}

size_t LinkedList::getSize() const {
    return size_;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    LinkedList::Node* node = list.head_;
    while (node != nullptr) {
        os << *(node->data) << " ";
        node = node->nextNode;
    }
    os << '\n';
}

void LinkedList::swap(LinkedList& other) noexcept {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
}

int LinkedList::compare(const char* lhs, const char* rhs) {
    const std::string strLhs(lhs);
    return strLhs.compare(rhs);
}
