/*
 * LeetCode 543. Diameter of Binary Tree
 * History:
 *  2020.8.18 : first version
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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        travel(root, diameter);
        return diameter;
    }

    int travel(TreeNode* root, int &diameter) {
        if (root == NULL)
            return 0;

        int left_height = travel(root->left, diameter);
        int right_height = travel(root->right, diameter);
        diameter = max(diameter, left_height+right_height);
        return max(left_height, right_height) + 1;
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(1);
    TreeNode *node2 = create_tree_node(2);
    TreeNode *node3 = create_tree_node(3);
    TreeNode *node4 = create_tree_node(4);
    TreeNode *node5 = create_tree_node(5);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, node4, node5);
    print_tree(node1);

    Solution solu;
    cout << solu.diameterOfBinaryTree(node1);

    return 0;
}
