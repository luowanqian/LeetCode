/*
 * LeetCode 543. Diameter of Binary Tree
 * History:
 *  2023.1.8 : first version
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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        travel(root);
        return diameter;
    }

    int travel(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = travel(root->left);
        int rightHeight = travel(root->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    Solution sol;

    TreeNode *node11 = create_tree_node(1);
    TreeNode *node12 = create_tree_node(2);
    TreeNode *node13 = create_tree_node(3);
    connect_tree_nodes(node11, node12, node13);
    TreeNode *node14 = create_tree_node(4);
    TreeNode *node15 = create_tree_node(5);
    connect_tree_nodes(node12, node14, node15);
    print_tree(node11);
    cout << "Diameter of Binary Tree: ";
    cout << sol.diameterOfBinaryTree(node11) << endl;

    return 0;
}