
#include "countWord.h"

int main(const int argc, char **argv) {
    if(argc != 3) {
        std::cerr << "insufficient data" << std::endl;
    }
    countWord obj1;
    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];
    try {
        obj1.readingAndCounting(inputFileName);
        obj1.sortDataAndWriteToCSV(outputFileName);

    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return (0);
}
