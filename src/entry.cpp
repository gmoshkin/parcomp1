#include <iostream>

#include "utils.h"
#include "bsort.h"
#include "sort.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    if (argc < 4) {
        int n1, n2;
        if (parseOptions(argc, argv, n1, n2) < 0) {
            return -1;
        }
        bsort(n1, n2);
    } else {
        numbers_t l1, l2;
        if (parseLists(argc, argv, l1, l2) < 0) {
            return -1;
        }
        sort(l1, l2);
    }
    return 0;
}
