//
// Created by Ta3ik on 20.10.2020.
//

#include "LinkedList.h"

LinkedList::const_iterator::const_iterator() {
    const_node = nullptr;
}

LinkedList::const_iterator::const_iterator(LinkedList::_List* el) {
    const_node = el;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator=(const LinkedList::const_iterator &other) {
    this->const_node = other.const_node;
    return (*this);
}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator &other) const {
    return(this->const_node->value != other.const_node->value);
}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator &other) const {
    return(this->const_node->value == other.const_node->value);
}

const value_type &LinkedList::const_iterator::operator*() const {
    return( static_cast<const value_type&>(this->const_node->value));
}

const value_type *LinkedList::const_iterator::operator->() const {
    return &((*this).const_node->value);
}

LinkedList::const_iterator &LinkedList::const_iterator::operator++() {
    this->const_node = const_node->next;
    return (*this);
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int) {
    LinkedList::const_iterator it;
    it.const_node = (*this).const_node;
    this->const_node = const_node->next;
    return (it);
}

LinkedList::const_iterator &LinkedList::const_iterator::operator--() {
    this->const_node = const_node->prev;
    return (*this);
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int) {
    LinkedList::const_iterator it;
    it.const_node = this->const_node;
    this->const_node = const_node->prev;
    return (it);
}

LinkedList::const_iterator LinkedList::cbegin() const {
    return(LinkedList::const_iterator(_endOfList->next));
}

LinkedList::const_iterator LinkedList::cend() const {
    return(LinkedList::const_iterator(_endOfList));
}
