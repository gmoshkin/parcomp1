#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <iostream>

#define DEBUG(x)
#ifndef DEBUG
#   define DEBUG(x) std::cout << x
#endif

typedef std::vector<int> numbers_t;
typedef numbers_t::const_iterator numbers_it;

std::ostream &operator <<(std::ostream &out, const numbers_t &);

int parseOptions(int argc, char *argv[], int &n1, int &n2);
int parseLists(int argc, char *argv[], numbers_t &n1, numbers_t &n2);

template <typename T1>
inline const T1 &max(const T1 &v1, const T1 &v2)
{
    return v1 > v2 ? v1 : v2;
}

#endif /* end of include guard: __UTILS_H__ */
