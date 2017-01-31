#include <utility>
#include <vector>

#include "nodes.h"

namespace Batcher {

typedef std::pair<node_t, node_t> pair_t;
typedef std::vector<pair_t> queue_t;

class Scheduler
{
private:
    queue_t queue;

public:
    void getSchedule(long len1);
    void getSchedule(long len1, long len2);
    void printSchedule();
    void toSort(const nodes_t &nodes);
    void toMerge(const nodes_t &topNodes, const nodes_t &botNodes);
    void addPair(const node_t node1, const node_t node2);
    void addPairs(const nodes_t &topNode, const nodes_t &botNode);
};

}
