#define CATCH_CONFIG_MAIN
#include <iostream>
#include "MyDll.h"
#include "catch.hpp"
//#include "test.cpp"
bool test1(){
    LinkedList f1 = LinkedList();
    f1.push_back(5);
    f1.push_front(7);
    int ans[2] = {7,5};
    int count = 0;
    for(LinkedList::iterator k = f1.begin(); k!=f1.end(); k++, count++){
        if(k.value!=ans[count]) return false;
    }
    return true;
}

TEST_CASE(){
    REQUIRE(test1() == true);
}

/*
int main(){
    LinkedList f1 = LinkedList();
    f1.push_back(5);
    f1.push_front(7);
    int ans[2] = {7,5};
    int cout = 0;
    for(LinkedList::iterator k = f1.begin(); k!=f1.end(); k++, cout++){
        if(k.value!=ans[cout]) return false;
    }
    return true;
}*/