#include <iostream>

#include "utils.h"
#include "bsort.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int n1, n2;
    if (parseOptions(argc, argv, n1, n2) < 0) {
        return -1;
    }
    bsort(n1, n2);
    return 0;
}
