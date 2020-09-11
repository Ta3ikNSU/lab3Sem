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
    std::ifstream fin;
    std::ofstream fout;

public:

    countWord();

    void openStream(char **argv);

    void mainMethod();

    void closeStream();

private:

    void readingAndCounting();

    void sortDataAndWriteToCSV();

    void writeToCSV(std::list<std::pair<std::string, int>> listPair);

    static bool isLetter(char a);

    static bool isDigit(char a);

    static bool compare(const std::pair<std::string, int> &arg1, const std::pair<std::string, int> &arg2);
};


#endif //LAB1_SEM2ND_COUNTWORD_H
