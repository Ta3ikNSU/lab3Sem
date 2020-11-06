//
// Created by Ta3ik on 20.10.2020.
//

#include "LinkedList.h"


LinkedList::iterator::iterator() {
    this->node = nullptr;
}

LinkedList::iterator::iterator(LinkedList::_List *el) {
    this->node = el;
}

LinkedList::iterator &LinkedList::iterator::operator=(const LinkedList::iterator &other) {
    if (this->node == other.node) return (*this);
    this->node = other.node;
    return (*this);
}


bool LinkedList::iterator::operator!=(const iterator &other) const {
    return (this->node != other.node);
}

bool LinkedList::iterator::operator==(const LinkedList::iterator &other) const {
    return (this->node == other.node);
}

value_type &LinkedList::iterator::operator*() {
    return this->node->value;
}

value_type *LinkedList::iterator::operator->() {
    return &(this->node->value);
}

LinkedList::iterator &LinkedList::iterator::operator++() {
    this->node = node->next;
    return *(this);
}

LinkedList::iterator LinkedList::iterator::operator++(int) {
    LinkedList::iterator it = LinkedList::iterator(this->node);
    this->node = this->node->next;
    return (it);
}

LinkedList::iterator &LinkedList::iterator::operator--() {
    this->node = node->prev;
    return ((*this));
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
    LinkedList::iterator it = LinkedList::iterator(this->node);
    this->node = node->prev;
    return (it);
}


LinkedList::iterator LinkedList::begin() {
    return (LinkedList::iterator(this->_endOfList->next));
}

LinkedList::iterator LinkedList::end() {
    return (LinkedList::iterator(this->_endOfList));
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator position) {
    LinkedList::iterator ret = LinkedList::iterator(position.node->next);
    ret.node->prev = ret.node->prev->prev;
    ret.node->prev->next = ret.node;
    delete position.node;
    _size--;
    return (ret);
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
    while (begin != end) {
        begin = erase(begin);
    }
    return (begin);
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator &before, const value_type &value) {
    _List *newList = new _List(value);
    newList->next = before.node;
    newList->prev = (--before).node;
    (++before).node->prev->next = newList;
    before.node->prev = newList;
    _size++;
    return (LinkedList::iterator(newList));
}