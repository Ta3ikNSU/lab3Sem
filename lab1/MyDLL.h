//
// Created by ta3ik on 25.09.2020.
//

#ifndef LAB1SEM3_MYDLL_H
#define LAB1SEM3_MYDLL_H


#include <iostream>

template<typename DATA>

class MyDLL{
protected:
    typedef struct _LL;

public:
    struct _LL* head;
    int size;

protected:
    typedef struct _LL{
        struct _LL* _next;
        struct _LL* _prev;
        DATA _data;
    }_LL;

public:
    bool isEmpty();
    void push_back(const DATA & value);
    void push_front(const DATA & value);
    void pop_back();
    void pop_fronf();
    void clear();


    class iterator;
    iterator begin() const;
    iterator end() const;
    iterator find(const DATA &) const;
    iterator erase(iterator position);
    iterator erase(iterator begin, iterator end);
    iterator insert(iterator before, const DATA & value);


    class iterator{
    public:
        explicit iterator(_LL* node);
        _LL* node() const;
        DATA* val() const;
        iterator& operator++();
        iterator& operator--();
        iterator& operator++(int);
        iterator& operator--(int);
        bool operator ==(const iterator&) const;
        bool operator !=(const iterator&) const;
    private:
        _LL* m_pNode;
    };
};


#endif //LAB1SEM3_MYDLL_H
