//
// Created by ta3ik on 25.09.2020.
//

#include "MyDll.h"

LinkedList::LinkedList() {
    endOfList = new _List();
    endOfList->next = endOfList;
    endOfList->prev = endOfList;
}

LinkedList::LinkedList(const LinkedList &other) {
    endOfList = new _List();
    for (_List *current = (other.endOfList)->next; current != (other.endOfList)->prev; current = current->next) {
        push_back(current->value);
    }
    _size = other._size;
}

LinkedList::LinkedList(LinkedList &&other) {
    endOfList = new _List();
    *this = other;
    _size = other._size;
    other.endOfList->next = other.endOfList->prev = nullptr;
    other._size = 0;

}

LinkedList::~LinkedList() {
    this -> clear();
    delete this -> endOfList;
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
    this->clear();
    for (auto cur = (other.endOfList)->next; cur != (other.endOfList); cur = cur->next) {
        this->push_back(cur->value);
    }
    return (*this);
}

LinkedList &LinkedList::operator=(LinkedList &&other) {
    this->endOfList = other.endOfList;
    other.endOfList->next = other.endOfList->prev = nullptr;
    other._size = 0;
    return (*this);
}

int LinkedList::size() const {
    return (_size);
}

bool LinkedList::empty() const {
    return (_size == 0);
}

value_type &LinkedList::front() {
    return this->endOfList->next->value;
}

const value_type &LinkedList::front() const {
    return static_cast<const value_type &>(this->endOfList->next->value);
}

value_type &LinkedList::back() {
    return this->endOfList->prev->value;
}

const value_type &LinkedList::back() const {
    return static_cast<const value_type &>(this->endOfList->prev->value);
}

int LinkedList::remove(const value_type &value) {
    int count = 0;
    for (auto cur = this->endOfList->next; cur != this->endOfList; cur = cur->next) {
        if (cur->value == value) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            auto rem = cur;
            cur = cur->prev;
            delete rem;
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
    auto rem = this->endOfList->prev;
    endOfList->prev->prev->next = endOfList->next;
    endOfList->prev = endOfList->prev->prev;
    endOfList->next ->prev = endOfList->prev;
    _size--;
    delete rem;
}

void LinkedList::pop_front() {
    if (empty()) {
        throw std::logic_error("list is empty");
    }
    auto rem = this->endOfList->next;
    endOfList->next->next->prev = endOfList->prev;
    endOfList->prev->next = endOfList->next;
    endOfList->next = endOfList->next->next;
    _size--;
    delete rem;
}

void LinkedList::push_back(const value_type &value) {
    auto newEl = new _List(value);
    if(_size!=0) {
        newEl->next = endOfList->next;
        newEl->prev = endOfList->prev;
        endOfList->prev->next = newEl;
        endOfList->prev = newEl;
        endOfList->next->prev = newEl;
    }else{
        newEl->next = newEl;
        newEl->prev = newEl;
        endOfList->prev = newEl;
        endOfList->next = newEl;
    }
    _size++;
}

void LinkedList::push_front(const value_type &value) {
    auto newEl = new _List(value);
    if(_size != 0) {
        newEl->next = endOfList->next;
        newEl->prev = endOfList->prev;
        endOfList->prev->next = newEl;
        endOfList->next = newEl;
    } else{
        newEl->next = newEl;
        newEl->prev = newEl;
        endOfList->prev = newEl;
        endOfList->next = newEl;
    }
    _size++;
}

LinkedList &LinkedList::operator+=(const LinkedList &other) {
    for (auto cur = (other.endOfList)->next; cur != other.endOfList; cur = cur->next) {
        push_back(cur->value);
    }
    return (*this);
}

bool operator!=(const LinkedList &left, const LinkedList &right) {
    auto curLeft = left.endOfList->next;
    auto curRight = right.endOfList->next;
    while (curLeft->value == curRight->value) {
        if ((curLeft == left.endOfList && curRight == right.endOfList)) return false;
        curLeft = curLeft->next;
        curRight = curRight->next;
    }
    return true;
}

bool operator==(const LinkedList &left, const LinkedList &right) {
    auto curLeft = left.endOfList->next;
    auto curRight = right.endOfList->next;
    while (curLeft->value == curRight->value) {
        if ((curLeft == left.endOfList->prev && curRight == right.endOfList->prev)) return true;
        curLeft = curLeft->next;
        curRight = curRight->next;
    }
    return false;
}