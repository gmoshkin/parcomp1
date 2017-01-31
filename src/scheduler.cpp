#include <iostream>
#include <utility>

#include "scheduler.h"
#include "nodes.h"

using std::cout;
using std::endl;
using namespace Batcher;

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

void Scheduler::addPairs(const nodes_t &topNodes, const nodes_t &botNodes)
{
    nodes_it it = topNodes.begin() + 1;
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

    if (topNodes.size() == 0 || botNodes.size() == 0) {
        cout << " nothin to merge" << endl;
        return;
    } else if (topNodes.size() == 1 && botNodes.size() == 1) {
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

void Scheduler::getSchedule(long n1)
{
    this->topNodesCount = n1;
    this->botNodesCount = 0;

    nodes_t nodes;
    insertRange(nodes, 0, n1);
    this->toSort(nodes);
}

void Scheduler::getSchedule(long n1, long n2)
{
    this->topNodesCount = n1;
    this->botNodesCount = n2;

    nodes_t topNodes, botNodes;
    insertRange(topNodes, 0, n1);
    insertRange(botNodes, n1, n1 + n2);
    this->toMerge(topNodes, botNodes);
}

void Scheduler::printSchedule()
{
    for (queue_it it = this->queue.begin(); it != this->queue.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void Scheduler::prettyPrintSchedule()
{
    for (int i = 0; i < this->topNodesCount - 1; i++) {
        cout << i << " ";
    }
    cout << this->topNodesCount - 1;
    if (this->botNodesCount != 0) {
        cout << "│";
    }
    for (int i = 0; i < this->botNodesCount; i++) {
        cout << i + this->topNodesCount << " ";
    }
    cout << endl;
    for (queue_it it = this->queue.begin(); it != this->queue.end(); it++) {
        this->printComparison(*it);
        cout << endl;
    }
}

void Scheduler::printComparison(const pair_t &pair)
{
    for (int i = 0; i < this->topNodesCount + this->botNodesCount; i++) {
        if (i == pair.first) {
            cout << "└─";
        } else if (i == pair.second) {
            cout << "┘ ";
        } else if (i > pair.first && i < pair.second) {
            cout << "──";
        } else {
            cout << "  ";
        }
    }
}
