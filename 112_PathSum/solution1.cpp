#include <stack>
#include <iostream>
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
    bool findPathSum(TreeNode *node, int expect_sum, int current_sum)
    {
        current_sum += node->val;

        // leaf node
        if (node->left == NULL && node->right == NULL) {
            if (current_sum == expect_sum)
                return true;
            else
                return false;
        }

        bool ret = false;
        if (!ret && node->left != NULL)
            ret = findPathSum(node->left, expect_sum, current_sum);
        if (!ret && node->right != NULL)
            ret = findPathSum(node->right, expect_sum, current_sum);

        return ret;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        return findPathSum(root, sum, 0);
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(5);
    TreeNode *node2 = create_tree_node(4);
    TreeNode *node3 = create_tree_node(8);
    TreeNode *node4 = create_tree_node(11);
    TreeNode *node5 = create_tree_node(13);
    TreeNode *node6 = create_tree_node(4);
    TreeNode *node7 = create_tree_node(7);
    TreeNode *node8 = create_tree_node(2);
    TreeNode *node9 = create_tree_node(1);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, node4, NULL);
    connect_tree_nodes(node3, node5, node6);
    connect_tree_nodes(node4, node7, node8);
    connect_tree_nodes(node6, NULL, node9);
    // print_tree(node1);

    Solution solu;
    int sum = 22;
    cout << solu.hasPathSum(node1, sum);

    return 0;
}
