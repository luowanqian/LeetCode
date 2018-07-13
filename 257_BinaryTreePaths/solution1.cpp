#include <iostream>
#include <vector>
#include <stack>
#include "BinaryTree.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, vector<string>& paths, vector<TreeNode*>& nodes)
    {
        if (node == NULL) {
            return;
        } else {
            nodes.push_back(node);

            if (node->left == NULL && node->right == NULL) {
                string path = "";
                for (int i=0; i<nodes.size(); i++) {
                    if (i == nodes.size()-1) {
                        path += to_string(nodes[i]->val);
                    } else {
                        path += to_string(nodes[i]->val);
                        path += "->";
                    }
                }
                paths.push_back(path);
            } else {
                dfs(node->left, paths, nodes);
                dfs(node->right, paths, nodes);
            }

            nodes.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return vector<string>();

        vector<string> paths;
        vector<TreeNode*> nodes;
        dfs(root, paths, nodes);

        return paths;
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(1);
    TreeNode *node2 = create_tree_node(2);
    TreeNode *node3 = create_tree_node(3);
    TreeNode *node4 = create_tree_node(5);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, NULL, node4);
    //print_tree(node1);

    Solution solu;
    vector<string> paths = solu.binaryTreePaths(node1);
    for (auto it=paths.begin(); it!=paths.end(); it++)
        cout << *it << endl;

    return 0;
}
