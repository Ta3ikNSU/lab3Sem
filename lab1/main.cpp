#define CATCH_CONFIG_MAIN
#include <iostream>
#include "LinkedList.h"
#include "catch.hpp"

bool test1(){
    LinkedList f1 = LinkedList();
    f1.push_back(5);
    f1.push_front(7);
    int ans[2] = {7,5};
    int cout = 0;
    for(LinkedList::iterator k = f1.begin(); k!=f1.end(); k++, cout++){
        if((*k)!=ans[cout]) return false;
    }
    return true;
}

bool test2(){
    LinkedList l1 = LinkedList();
    for(int i = 0; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator k = l1.end();
    k--;
    if(*k == 9) return(true);
    return(false);
}

bool test3(){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator k = l1.end();
    k++;
    if(*k == 1) return(true);
    return(false);
}

bool test4(){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList l2 = LinkedList();
    for(int i = 10; i<20;i++){
        l1.push_back(i);
    }
    l1+=l2;
    int ans[20];
    for(int i = 0; i < 20; i++) ans[i] = i + 1;
    int cout = 0;
    for(LinkedList::iterator k = l1.begin(); k!=l1.end(); k++, cout++){
        if((*k)!=ans[cout]) return false;
    }
    return(true);
}

bool test5(){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator k = l1.begin();
    for(; *k !=5; k++){}
    l1.insert(k,15);
    if(*(--k)==15) return true;
    return(false);
}

bool test6(){
    LinkedList l1 = LinkedList();
    for(int i = 1; i<10;i++){
        l1.push_back(i);
    }
    LinkedList::iterator it1 = l1.begin();
    LinkedList::iterator it2 = l1.end();
    it2--;
    it2--;
    l1.erase(it1,it2);
    if(l1.size() == 2) {
        return true;
    }
    return false;
}
/*
int main(){
    if(test1()!=true) return(false);
    if(test2()!=true) return(false);
    if(test3()!=true) return(false);
    if(test4()!=true) return(false);
    if(test5()!=true) return(false);
    if(test6()!=true) return(false);
}
 */
TEST_CASE(){
    REQUIRE(test1()==true);
    REQUIRE(test2()==true);
    REQUIRE(test3()==true);
    REQUIRE(test4()==true);
    REQUIRE(test5()==true);
    REQUIRE(test6()==true);
}



