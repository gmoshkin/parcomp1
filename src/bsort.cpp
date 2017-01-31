#include <iostream>

#include "scheduler.h"

using std::cout;
using std::endl;

int bsort(int n1, int n2)
{
    Batcher::Scheduler sched;

    if (n2 == 0) {
        sched.getSchedule(n1);
    } else {
        sched.getSchedule(n1, n2);
    }
    sched.printSchedule();
    return 0;
}
