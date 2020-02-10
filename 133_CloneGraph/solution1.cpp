#include "graph.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<int, Node*> marked;
public:
    Node* cloneGraph(Node* node) {
        if (NULL == node)
            return NULL;

        return dfs(node);
    }

    Node* dfs(Node* node) {
        vector<Node*> neighbors = node->neighbors;
        Node *new_node = new Node(node->val);
        marked.insert({node->val, new_node});

        for (auto i=0; i<neighbors.size(); i++) {
            auto search = marked.find(neighbors[i]->val);
            if (search == marked.end())
                new_node->neighbors.push_back(dfs(neighbors[i]));
            else
                new_node->neighbors.push_back(search->second);
        }

        return new_node;
    }
};

int main()
{
    int V = 4;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    Graph graph(V);
    graph.add_edge(node1, node2);
    graph.add_edge(node2, node3);
    graph.add_edge(node3, node4);
    graph.add_edge(node4, node1);
    graph.print_graph();
    cout << endl;

    Solution solu;
    Node *new_node = solu.cloneGraph(node1);

    return 0;
}
