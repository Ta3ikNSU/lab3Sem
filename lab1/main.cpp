#define CATCH_CONFIG_MAIN
#include <iostream>
#include "LinkedList.h"
#include "catch.hpp"

TEST_CASE("Common test"){
    LinkedList f1 = LinkedList();
    f1.push_back(5);
    f1.push_front(7);
    int ans[2] = {7,5};
    int count = 0;
    for(LinkedList::iterator k = f1.begin(); k!=f1.end(); k++, count++) {
        REQUIRE((*k) == ans[count]);
    }
}

TEST_CASE("Test operator* --/++(int) for iterator"){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator k = l1.end();
    k++;
    REQUIRE(*k == 1);
    --k;
    REQUIRE(*(--k)==9);
}

TEST_CASE("Push Back && operator+="){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    REQUIRE(l1.size()==9);
    LinkedList l2 = LinkedList();
    for(int i = 10; i<20;i++){
        l2.push_back(i);
    }
    REQUIRE(l2.size() == 10);
    l1+=l2;
    int ans[20];
    for(int i = 0; i < 20; i++) ans[i] = i + 1;
    int count = 0;
    REQUIRE(l1.size() == 19);
    for(LinkedList::iterator k = l1.begin(); k!=l1.end(); k++, count++){
        REQUIRE((*k)==ans[count]);
    }
}

TEST_CASE("insert"){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator k = l1.begin();
    for(; *k !=5; k++){}
    l1.insert(k,15);
    REQUIRE(*(--k)==15);
}

TEST_CASE("Single erase + mult erase"){
    LinkedList l1 = LinkedList();
    int answ[20];
    int count=10;
    for(int i = 1; i < 9;i++) answ[i] = i;
    for(int i = 9; i < 20;i++) answ[i] = i+10;
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator it1 = --l1.end();
    for(int i = 10; i<20;i++){
        l1.push_back(i);
    }
    LinkedList::iterator it2 = --l1.end();
    for(int i = 20; i<30;i++, count++){
        l1.push_back(i);
        answ[count] = i;
    }
    REQUIRE(l1.size() == 29);
    it2 = l1.erase(it1,it2);
    REQUIRE(l1.size()==19);
    count = 1;
    for(auto it = l1.begin(); it!=l1.end();it++, count++){
        REQUIRE(*it == answ[count]);
    }
    it2 = l1.erase(it2); //rm 19
    REQUIRE(*(it2) == 20);
}
/*
TEST_CASE("Test String"){
    std::string hello = "Hello, ";
    std::string world = " World";
    LinkedList l1 = LinkedList();
    l1.push_front(hello);
    l1.push_back(world);
    LinkedList::iterator it = l1.begin();
    REQUIRE((*it) == hello);
    REQUIRE(*(++it) == world);
}*/
