//
// Created by ta3ik on 10.09.2020.
//

#ifndef LAB1_SEM2ND_COUNTWORD_H
#define LAB1_SEM2ND_COUNTWORD_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <list>

class countWord {

    int count;
    std::map<std::string, int> wordMap;

public:

    countWord();

    void readingAndCounting(std::string nameInputFile);

    void sortDataAndWriteToCSV(std::string nameOutputFile);

private:

    void writeToCSV(std::list<std::pair<std::string, int>> listPair,std::string nameOutputFile);
};


#endif //LAB1_SEM2ND_COUNTWORD_H
