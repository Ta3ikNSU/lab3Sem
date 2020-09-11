//
// Created by ta3ik on 10.09.2020.
//
#include <iostream>
#include <list>
#include <cmath>
#include "countWord.h"


countWord::countWord() {
    count = 0;
}

void countWord::openStream(char **argv) {
    fin.open(argv[1], std::ios::in);
    fout.open(argv[2], std::ios::out);
}

void countWord::mainMethod() {
    readingAndCounting();
    sortDataAndWriteToCSV();
}

void countWord::closeStream() {
    fin.close();
    fout.close();
}

void countWord::readingAndCounting() {
    std::string buffer, newWord;
    bool prevSymbolIsSep = true;
    while (getline(fin, buffer)) {
        for (int i = 0; i < buffer.size(); i++) {
            char curSymbol = buffer[i];
            if (isDigit(curSymbol) || isLetter(curSymbol)) {
                if (prevSymbolIsSep == true) count++;
                prevSymbolIsSep = false;
                newWord += curSymbol;
            } else {
                prevSymbolIsSep = true;
                wordMap[newWord]++;
                newWord = "";
            }
        }
    }
}

void countWord::sortDataAndWriteToCSV() {
    std::list<std::pair<std::string, int>> listPair;
    std::map<std::string, int>::iterator it;
    for (it = wordMap.begin(); it != wordMap.end(); it++) {
        std::pair<std::string, int> dataToList;
        dataToList.first = it->first;
        dataToList.second = it->second;
        listPair.push_front(dataToList);
    }
    listPair.sort(countWord::compare);
    writeToCSV(listPair);
}

void countWord::writeToCSV(std::list<std::pair<std::string, int>> listPair) {
    std::list<std::pair<std::string, int>>::iterator it;
    for (it = listPair.begin(); it != listPair.end(); it++) {
        fout << it->first << " " << it->second << " " << floor((double) it->second / double(count) * 100 + 0.05)
             << std::endl;
    }
}


bool countWord::isDigit(char a) {
    if (a >= '0' && a <= '9') return true;
    else return false;
}

bool countWord::isLetter(char a) {
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z') return true;
    else return false;
}

bool countWord::compare(const std::pair<std::string, int> &arg1, const std::pair<std::string, int> &arg2) {
    if (arg1.second > arg2.second) return true;
    else return false;
}






