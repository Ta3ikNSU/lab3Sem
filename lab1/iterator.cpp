//
// Created by Ta3ik on 20.10.2020.
//

#include "MyDll.h"


LinkedList::iterator::iterator() {
    this->node = nullptr;
}

LinkedList::iterator::iterator(LinkedList::_List* el) {
    this->node = el;
    this->value = el->value;
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
    return this->node->value;
}

value_type *LinkedList::iterator::operator->() {
    return &(this->node->value);
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
    this->node = this->node->prev;
    this->value = this->node->value;
    return (*this);
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
    LinkedList::iterator it = LinkedList::iterator(this->node);
    this->node = node->prev;
    this->value = this->node->value;
    return (it);
}


LinkedList::iterator LinkedList::begin() {
    return(LinkedList::iterator(this->endOfList->next));
}

LinkedList::iterator LinkedList::end() {
    return(LinkedList::iterator(this->endOfList->prev));
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
    if(begin.node != endOfList->next || end.node != endOfList->prev) {
        LinkedList::iterator ret = --begin; ++begin;
        ret.node->next = end.node->next;
        if(this->endOfList->next == begin.node){
            endOfList->next = end.node->next;
            ret.node->next = end.node->next;
        }
        for (; begin != end; begin++) {
            begin = erase(begin);
        }
        return (ret);
    } else {
        throw std::logic_error("use clear");
    }
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator &before, const value_type &value) {
    _List* newList = new _List(value);
    if(endOfList->next != before.node) {
        newList->next = before.node;
        newList->prev = (--before).node;
        (--before.node)->next = newList;
        (++(++before)).node->prev = newList;
        return (LinkedList::iterator(newList));
    }else {
        before.node->prev = newList;
        endOfList->next = newList;
        newList->prev = endOfList->prev;
        newList->next = before.node;
        return(LinkedList::iterator(newList));
    }
}