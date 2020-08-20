/*
 * 2020-08-20
 * Top-down solution
 */
#include "BinaryTree.h"
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int m_max_depth;
public:
    int maxDepth(TreeNode* root) {
        m_max_depth = 0;

        if (root == NULL)
            return m_max_depth;
        max_depth(root, 1);

        return m_max_depth;
    }

    void max_depth(TreeNode* root, int depth)
    {
        if (root == NULL)
            return;

        if (NULL == root->left && NULL == root->right) {
            m_max_depth = max(m_max_depth, depth);
        }
        max_depth(root->left, depth + 1);
        max_depth(root->right, depth + 1);
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

    // print_tree_node(node1);

    Solution solu;
    int depth = solu.maxDepth(node1);
    cout << "Depth of tree: " << depth << endl;

    return 0;
}
