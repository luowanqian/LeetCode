#include "graph.h"
#include <vector>
#include <iostream>


Graph::Graph(int V)
{
    num_edges = 0;
    num_vertexes = V;
    adjacency = std::vector<Node*>(V+1, NULL);
}

void Graph::add_edge(Node* src, Node* dest)
{
    if (NULL == src || NULL == dest)
        return;
    if (src->val > num_vertexes || dest->val > num_vertexes)
        return;
    if (src->val < 1 || dest->val < 1)
        return;

    int src_val = src->val, dest_val = dest->val;

    if (NULL == adjacency[src_val])
        adjacency[src_val] = src;
    if (NULL == adjacency[dest_val])
        adjacency[dest_val] = dest;

    adjacency[src_val]->neighbors.push_back(dest);
    adjacency[dest_val]->neighbors.push_back(src);
    num_edges++;
}

void Graph::print_graph()
{
    Node *node = NULL;
    for (int i=1; i<=num_vertexes; i++) {
        node = adjacency[i];
        if (NULL != node) {
            std::cout << node->val << ": ";
            for (auto it=node->neighbors.begin(); it!=node->neighbors.end(); it++)
                std::cout << (*it)->val << ", ";
            std::cout << std::endl;
        }
    }
}


