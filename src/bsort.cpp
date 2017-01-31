#include "batcher.h"

using namespace Batcher;

void Scheduler::bisect(const nodes_t &nodes)
{
    cout << "bisecting ";
    this->printNodes(nodes);

    if (nodes.size() < 2) {
        cout << "nothing to bisect" << endl;
        return;
    }

    nodes_t topNodes(nodes.begin(), nodes.begin() + nodes.size() / 2);
    nodes_t botNodes(nodes.begin() + nodes.size() / 2, nodes.end());

    cout << "top: ";
    this->printNodes(topNodes);
    cout << "bottom: ";
    this->printNodes(botNodes);

    this->bisect(topNodes);
    this->bisect(botNodes);

    this->shuffle(topNodes, botNodes);
}

void Scheduler::shuffle(const nodes_t &topNodes, const nodes_t &botNodes)
{
    cout << "shuffling TODO" << endl;
}

void Scheduler::printNodes(const nodes_t &nodes)
{
    cout << "[ ";
    for (nodes_const_it it = nodes.begin(); it != nodes.end(); it++) {
        cout << *it << " ";
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
    return 0;
}
