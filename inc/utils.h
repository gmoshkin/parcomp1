#ifndef __UTILS_H__
#define __UTILS_H__

#define DEBUG(x)
#ifndef DEBUG
#   define DEBUG(x) std::cout << x
#endif
int parseOptions(int argc, char *argv[], int &n1, int &n2);

#endif /* end of include guard: __UTILS_H__ */
