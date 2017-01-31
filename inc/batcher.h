#include <utility>
#include <vector>

namespace Batcher {

typedef std::pair<int, int> pair_t;
typedef std::vector<pair_t> queue_t;
typedef std::vector<int> nodes_t;
typedef nodes_t::const_iterator nodes_const_it;

class Scheduler
{
private:
    queue_t queue;

public:
    void makeSchedule(long len1);
    void makeSchedule(long len1, long len2);
    void printSchedule();
    void bisect(const nodes_t &nodes);
    void shuffle(const nodes_t &topNodes, const nodes_t &botNodes);
    void printNodes(const nodes_t &nodes);
};

}
