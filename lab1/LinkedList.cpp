//
// Created by ta3ik on 25.09.2020.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    _endOfList = new _List();
    _endOfList->next = _endOfList;
    _endOfList->prev = _endOfList;
}

LinkedList::LinkedList(const LinkedList &other) {
    _endOfList = new _List();
    for (_List *current = (other._endOfList)->next; current != (other._endOfList)->prev; current = current->next) {
        push_back(current->value);
    }
    _size = other._size;
}

LinkedList::LinkedList(LinkedList &&other) {
    _endOfList = new _List();
    *this = other;
    _size = other._size;
    other._endOfList->next = other._endOfList->prev = nullptr;
    other._size = 0;

}

LinkedList::~LinkedList() {
    this->clear();
    delete this->_endOfList;
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
    if (this->_endOfList == other._endOfList) return (*this);
    this->clear();
    for (auto cur = (other._endOfList)->next; cur != (other._endOfList); cur = cur->next) {
        this->push_back(cur->value);
    }
    return (*this);
}

LinkedList &LinkedList::operator=(LinkedList &&other) {
    if (this == &other) return (*this);
    this->_endOfList = other._endOfList;
    other._endOfList = nullptr;
    other._size = 0;
    delete other._endOfList;
    return (*this);
}

int LinkedList::size() const {
    return (_size);
}

bool LinkedList::empty() const {
    return (_size == 0);
}

value_type &LinkedList::front() {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    return *begin();
}

const value_type &LinkedList::front() const {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    return *cbegin();
}

value_type &LinkedList::back() {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    return *--end();
}

const value_type &LinkedList::back() const {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    return *--cend();
}

int LinkedList::remove(const value_type &value) {
    int count = 0;
    for (auto it = begin(); it != end(); it++) {
        if (*(it) == value) {
            erase(it);
            _size--;
            count++;
        }
    }
    return (count);
}

void LinkedList::clear() {
    while (!empty()) {
        pop_front();
    }
}

void LinkedList::pop_back() {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    LinkedList::iterator it = --end();
    erase(it);
}

void LinkedList::pop_front() {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    LinkedList::iterator it = begin();
    erase(it);
}

void LinkedList::push_back(const value_type &value) {
    LinkedList::iterator it = end();
    insert(it, value);
}

void LinkedList::push_front(const value_type &value) {
    LinkedList::iterator it = begin();
    insert(it, value);
}

LinkedList &LinkedList::operator+=(const LinkedList &other) {
    for (auto cur = (other._endOfList)->next; cur != other._endOfList; cur = cur->next) {
        push_back(cur->value);
    }
    return (*this);
}

bool operator!=(const LinkedList &left, const LinkedList &right) {
    auto curLeft = left._endOfList->next;
    auto curRight = right._endOfList->next;
    while (curLeft->value == curRight->value) {
        if ((curLeft == left._endOfList && curRight == right._endOfList)) return false;
        curLeft = curLeft->next;
        curRight = curRight->next;
    }
    return true;
}

bool operator==(const LinkedList &left, const LinkedList &right) {
    return !(left != right);
}

LinkedList operator+(const LinkedList &left, const LinkedList &right) {
    LinkedList *el = new LinkedList(left);
    *el += right;
    return (*el);
}
