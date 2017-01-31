#include <iostream>

#include "nodes.h"

using std::cout;
using std::endl;

namespace Batcher {

void printNodes(const nodes_t &nodes)
{
    cout << "[ ";
    for (nodes_const_it it = nodes.begin(); it != nodes.end(); it++) {
        cout << *it << " ";
    }
    cout << "]";
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

void insertRange(nodes_t &nodes, int start, int end)
{
    for (int i = start; i < end; i++) {
        nodes.push_back(i);
    }
}

}