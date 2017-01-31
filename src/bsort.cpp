#include <iostream>

#include "scheduler.h"

using std::cout;
using std::endl;

int bsort(int n1, int n2)
{
    cout << n1 << " " << n2 << " 0" << endl;

    Batcher::Scheduler sched;

    if (n2 == 0) {
        sched.getSchedule(n1);
    } else {
        sched.getSchedule(n1, n2);
    }
    sched.printSchedule();
    cout << sched.getComparisonsCount() << endl;
    cout << sched.getTactsCount() << endl;
    if (n1 + n2 <= 11) {
        sched.prettyPrintSchedule();
    }
    return 0;
}
