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
    int travel(TreeNode* node) {
        if (node == NULL) {
            return 0;
        } else {
            int left, right;

            left = travel(node->left);
            right = travel(node->right);

            return max(left, right) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            int left, right;

            left = travel(root->left);
            right = travel(root->right);
            if ((left - right) > 1 || (right - left) > 1)
                return false;

            return isBalanced(root->left) && isBalanced(root->right);
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
    //print_tree(node1);

    Solution solu;
    cout << solu.isBalanced(node1) << endl;

    return 0;
}
