//
// Created by Ta3ik on 25.09.2020.
//

#include "LinkedList.h"

LinkedList::_List::_List() {
    value = value_type();

    next = nullptr;
    prev = nullptr;
}

LinkedList::_List::_List(value_type &val) {
    value = val;

    next = nullptr;
    prev = nullptr;
}

LinkedList::_List::_List(const value_type &val) {
    value = val;

    next = nullptr;
    prev = nullptr;
}

