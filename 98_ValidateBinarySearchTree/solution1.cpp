#include <iostream>
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
    bool isValidBST(TreeNode* root) {
        long res = numeric_limits<long>::min();
        return traversal(root,res);
    }

    bool traversal(TreeNode* root, long& res) {
        if (root == NULL) {
            return true;
        }

        bool left = traversal(root->left, res);
        if (!left || root->val <= res)
            return false;

        res = root->val;

        bool right = traversal(root->right, res);
        if (!right)
            return false;

        return true;
    }
};

int main()
{
    Solution solu;

    TreeNode *node1_1 = create_tree_node(2);
    TreeNode *node1_2 = create_tree_node(1);
    TreeNode *node1_3 = create_tree_node(3);
    connect_tree_nodes(node1_1, node1_2, node1_3);
//    print_tree(node1);
    cout << "Test case 1: "
         << solu.isValidBST(node1_1)
         << endl;

    TreeNode *node2_1 = create_tree_node(5);
    TreeNode *node2_2 = create_tree_node(1);
    TreeNode *node2_3 = create_tree_node(4);
    TreeNode *node2_4 = create_tree_node(3);
    TreeNode *node2_5 = create_tree_node(6);
    connect_tree_nodes(node2_1, node2_2, node2_3);
    connect_tree_nodes(node2_3, node2_4, node2_5);
//    print_tree(node2_1);
    cout << "Test case 2: "
         << solu.isValidBST(node2_1)
         << endl;

    return 0;
}