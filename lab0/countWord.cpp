//
// Created by ta3ik on 10.09.2020.
//
#include <iostream>
#include <list>
#include <cmath>
#include "countWord.h"

bool isDigit(char a) {
    if (a >= '0' && a <= '9') return true;
    else return false;
}

bool isLetter(char a) {
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) return true;
    else return false;
}

bool compare(const std::pair<std::string, int> &arg1, const std::pair<std::string, int> &arg2) {
    if (arg1.second > arg2.second) return true;
    else return false;
}


countWord::countWord() {
    count = 0;
}

void countWord::readingAndCounting(std::string nameInputFile) {
    std::ifstream fin;
    fin.open( nameInputFile, std::ios::in);
    if(!fin){
        throw std::invalid_argument("input file not found");
    }
    std::string buffer, newWord;
    bool prevSymbolIsSep = true;
    while (getline(fin, buffer)) {
        for (int i = 0; i <= buffer.size()-1; i++) {
            char curSymbol = buffer[i];
            if (isDigit(curSymbol) || isLetter(curSymbol)) {
                if (prevSymbolIsSep == true) count++;
                prevSymbolIsSep = false;
                newWord += curSymbol;
                if(i == buffer.size()-1){
                    wordMap[newWord]++;
                    newWord = "";
                }
            } else {
                if(prevSymbolIsSep == false) {
                    wordMap[newWord]++;
                    newWord = "";
                }
                prevSymbolIsSep = true;

            }
        }
    }
    fin.close();
}

void countWord::sortDataAndWriteToCSV(std::string nameOutputFile) {

    std::list<std::pair<std::string, int>> listPair;
    std::map<std::string, int>::iterator it;
    for (it = wordMap.begin(); it != wordMap.end(); it++) {
        std::pair<std::string, int> dataToList;
        dataToList.first = it->first;
        dataToList.second = it->second;
        listPair.push_back(dataToList);
    }
    listPair.sort(compare);
    writeToCSV(listPair, nameOutputFile);
}

void countWord::writeToCSV(std::list<std::pair<std::string, int>> listPair, std::string nameOutputFile) {
    std::ofstream fout;
    fout.open( nameOutputFile, std::ios::out);
    if(!fout){
        throw std::invalid_argument("output file not open");
    }
    std::list<std::pair<std::string, int>>::iterator it;
    for (it = listPair.begin(); it != listPair.end(); it++) {
        fout << it->first << "," << it->second << "," << floor((double) it->second / double(count) * 1000000 + 0.5)/10000.0
             << std::endl;
    }
    fout.close();
}









