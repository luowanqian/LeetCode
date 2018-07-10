#include <iostream>
#include <queue>
#include <vector>
#include <limits>
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        queue<TreeNode*> nodes;
        TreeNode *current_node;
        vector<int> node_values;
        int current_level, next_level;
        int left, right;

        nodes.push(root);
        current_level = 1;
        next_level = 0;
        while (!nodes.empty()) {
            current_node = nodes.front();
            if (current_node->left != NULL) {
                next_level++;
                node_values.push_back(current_node->left->val);
                nodes.push(current_node->left);
            } else {
                node_values.push_back(INT_MAX);
            }

            if (current_node->right != NULL) {
                next_level++;
                node_values.push_back(current_node->right->val);
                nodes.push(current_node->right);
            } else {
                node_values.push_back(INT_MAX);
            }

            nodes.pop();
            current_level--;

            if (current_level == 0) {
                current_level = next_level;
                next_level = 0;

                left = 0;
                right = node_values.size() - 1;
                while (left < right) {
                    if (node_values[left] != node_values[right])
                        return false;
                    left++;
                    right--;
                }

                node_values.clear();
            }
        }

        return true;
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(1);
    TreeNode *node2 = create_tree_node(2);
    TreeNode *node3 = create_tree_node(2);
    TreeNode *node4 = create_tree_node(3);
    TreeNode *node5 = create_tree_node(3);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, NULL, node4);
    connect_tree_nodes(node3, NULL, node5);
    //print_tree(node1);

    Solution solu;
    cout << "Symmetric: " << solu.isSymmetric(node1) << endl;

    return 0;
}
