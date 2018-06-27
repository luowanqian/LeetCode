#include <iostream>
#include <algorithm>
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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int left_depth, right_depth;

            left_depth = minDepth(root->left);
            right_depth = minDepth(root->right);

            if (left_depth == 0)
                return right_depth + 1;
            else if (right_depth == 0)
                return left_depth + 1;
            else
                return min(left_depth, right_depth) + 1;
        }
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(3);
    TreeNode *node2 = create_tree_node(9);
    TreeNode *node3 = create_tree_node(20);
    TreeNode *node4 = create_tree_node(15);
    TreeNode *node5 = create_tree_node(7);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node3, node4, node5);

    Solution solu;
    cout << solu.minDepth(node1) << endl;

    node1 = create_tree_node(1);
    node2 = create_tree_node(2);
    connect_tree_nodes(node1, node2, NULL);
    cout << solu.minDepth(node1) << endl;

    return 0;
}
