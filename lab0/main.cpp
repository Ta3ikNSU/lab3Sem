
#include "countWord.h"

int main(const int argc, char **argv) {
    countWord obj1;
    obj1.openStream(argv);
    obj1.mainMethod();
    obj1.closeStream();
    return (0);
}
