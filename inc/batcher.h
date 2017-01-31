#include <utility>
#include <vector>

namespace Batcher {

typedef int node_t;
typedef std::pair<node_t, node_t> pair_t;
typedef std::vector<pair_t> queue_t;
typedef std::vector<node_t> nodes_t;
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
    void addPair(const node_t node1, const node_t node2);
};

}
