#include <utility>

#include "batcher.h"

using namespace Batcher;

void printNodes(const nodes_t &nodes)
{
    cout << "[ ";
    for (nodes_const_it it = nodes.begin(); it != nodes.end(); it++) {
        cout << *it << " ";
    }
    cout << "]";
}

void Scheduler::bisect(const nodes_t &nodes)
{
    cout << "bisecting ";
    printNodes(nodes);

    if (nodes.size() < 2) {
        cout << " nothing to bisect" << endl;
        return;
    }

    nodes_t topNodes(nodes.begin(), nodes.begin() + nodes.size() / 2);
    nodes_t botNodes(nodes.begin() + nodes.size() / 2, nodes.end());

    cout << " → ";
    printNodes(topNodes);
    cout << " ";
    printNodes(botNodes);
    cout << endl;

    this->bisect(topNodes);
    this->bisect(botNodes);

    this->shuffle(topNodes, botNodes);
}

void Scheduler::shuffle(const nodes_t &topNodes, const nodes_t &botNodes)
{
    cout << "shuffling ";
    printNodes(topNodes);
    cout << " ";
    printNodes(botNodes);
    cout << endl;

    unsigned int totalCount = topNodes.size() + botNodes.size();
    if (totalCount < 2) {
        cout << " nothin to shuffle" << endl;
        return;
    } else if (totalCount == 2) {
        this->addPair(topNodes[0], botNodes[0]);
        return;
    }
    cout << "TODO" << endl;
}

void Scheduler::addPair(const node_t node1, const node_t node2)
{
    cout << "adding (" << node1 << "," << node2 << ")" << endl;
    this->queue.push_back(std::make_pair(node1, node2));
}

void Scheduler::printSchedule()
{
    cout << "[ ";
    queue_t::const_iterator it = this->queue.begin();
    for (; it != this->queue.end(); it++) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << "]" << endl;
}

void insertRange(nodes_t &nodes, int start, int end)
{
    for (int i = start; i < end; i++) {
        nodes.push_back(i);
    }
}

int bsort(int n1, int n2)
{
    nodes_t nodes;
    Scheduler sched;

    insertRange(nodes, 0, n1);
    sched.bisect(nodes);
    sched.printSchedule();
    return 0;
}
