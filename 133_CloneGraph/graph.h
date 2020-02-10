#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Graph {
private:
    int num_edges;
    int num_vertexes;
    std::vector<Node*> adjacency;

public:
    Graph(int V);
    void add_edge(Node* src, Node* dest);
    void print_graph();
};

#endif //_GRAPH_H
