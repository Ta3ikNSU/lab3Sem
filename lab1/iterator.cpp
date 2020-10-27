//
// Created by Ta3ik on 20.10.2020.
//

#include "MyDll.h"


LinkedList::iterator::iterator() {
    node = nullptr;
}

LinkedList::iterator::iterator(LinkedList::_List* el) {
    node = el;
    value = el->value;
}

LinkedList::iterator &LinkedList::iterator::operator=(const LinkedList::iterator &other) {
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
    return (*this).node->value;
}

value_type *LinkedList::iterator::operator->() {
    return &((*this).node->value);
}

LinkedList::iterator &LinkedList::iterator::operator++() {
    this->node = node->next;
    this->value = this->node->value;
    return (*this);
}

LinkedList::iterator LinkedList::iterator::operator++(int) {
    LinkedList::iterator it = LinkedList::iterator(this->node);
    this->node = this->node->next;
    this->value = this->node->value;
    return (it);
}

LinkedList::iterator &LinkedList::iterator::operator--() {
    this->node = node->prev;
    this->value = this->node->value;
    return (*this);
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
    LinkedList::iterator it;
    it.node = this->node;
    this->node = node->prev;
    this->value = this->node->value;
    return (it);
}


LinkedList::iterator LinkedList::begin() {
    return(LinkedList::iterator(endOfList->next));
}

LinkedList::iterator LinkedList::end() {
    return(LinkedList::iterator(endOfList->prev));
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator position) {
    LinkedList::iterator ret = position--;

    position.node->next->prev = (--position).node;
    position.node->prev->next = (++position).node;
    delete position.node;
    _size--;
    return(ret);
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
    LinkedList::iterator ret = begin--;
    ret.node->next = end.node->next;
    for(; begin!=end; begin++){
        begin = erase(begin);
    }
    return (ret);
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type &value) {
    _List* newList = new _List(value);
    newList->next = before.node;
    newList->prev = (--before).node;
    (--before.node)->next = newList;
    before.node->prev = newList;
    return(LinkedList::iterator(newList));

}