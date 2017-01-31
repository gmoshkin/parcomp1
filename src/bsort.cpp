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

void Scheduler::toSort(const nodes_t &nodes)
{
    cout << "to sort ";
    printNodes(nodes);

    if (nodes.size() < 2) {
        cout << " nothing to sort" << endl;
        return;
    }

    nodes_t topNodes(nodes.begin(), nodes.begin() + nodes.size() / 2);
    nodes_t botNodes(nodes.begin() + nodes.size() / 2, nodes.end());

    cout << " → ";
    printNodes(topNodes);
    cout << " ";
    printNodes(botNodes);
    cout << endl;

    this->toSort(topNodes);
    this->toSort(botNodes);

    this->toMerge(topNodes, botNodes);

}

void split(const nodes_t &nodes, nodes_t &oddNodes, nodes_t &evenNodes)
{
    bool odd = true;
    for (nodes_const_it it = nodes.begin(); it != nodes.end(); it++) {
        if (odd) {
            oddNodes.push_back(*it);
        } else {
            evenNodes.push_back(*it);
        }
        odd = !odd;
    }
}

void Scheduler::addPairs(const nodes_t &topNodes, const nodes_t &botNodes)
{
    nodes_const_it it = topNodes.begin() + 1;
    for (; it != topNodes.end() && it + 1 != topNodes.end(); it += 2) {
        this->addPair(*it, *(it + 1));
    }
    it = botNodes.begin();
    if (topNodes.size() % 2 == 0) {
        this->addPair(topNodes.back(), *it);
        it++;
    }
    for (; it != botNodes.end() && it + 1 != botNodes.end(); it += 2) {
        this->addPair(*it, *(it + 1));
    }
}

void Scheduler::toMerge(const nodes_t &topNodes, const nodes_t &botNodes)
{
    cout << "to merge ";
    printNodes(topNodes);
    cout << " ";
    printNodes(botNodes);
    cout << endl;

    unsigned int totalCount = topNodes.size() + botNodes.size();
    if (totalCount < 2) {
        cout << " nothin to merge" << endl;
        return;
    } else if (totalCount == 2) {
        this->addPair(topNodes[0], botNodes[0]);
        return;
    }
    nodes_t topOddNodes, topEvenNodes, botOddNodes, botEvenNodes;

    split(topNodes, topOddNodes, topEvenNodes);
    split(botNodes, botOddNodes, botEvenNodes);

    cout << "odd ";
    this->toMerge(topOddNodes, botOddNodes);
    cout << "even ";
    this->toMerge(topEvenNodes, botEvenNodes);

    cout << "joining ";
    printNodes(topNodes);
    cout << " + ";
    printNodes(botNodes);
    cout << endl;
    this->addPairs(topNodes, botNodes);
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
