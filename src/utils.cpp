#include <cstdlib>
#include <iostream>

using std::cerr;

const char *usage =
"Usage: bsort n1 n2\n"
"\n"
"in case n2 != 0:\n"
"   n1      the number of elements in the first ordered group\n"
"   n2      the number of elements in the second ordered group\n"
"\n"
"in case n2 == 0:\n"
"   n1      the number of elements in the unordered group\n";

void printUsage()
{
    cerr << usage;
}

int parseOptions(int argc, char *argv[], int &n1, int &n2)
{
    if (argc < 3) {
        printUsage();
        return -1;
    }
    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
    return 0;
}
