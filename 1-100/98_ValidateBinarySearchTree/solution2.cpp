#include "BinaryTree.h"
#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        return valid(root, LLONG_MIN, LLONG_MAX);
    }

    bool valid(TreeNode* node, long long lb, long long ub) {
        if (node == nullptr)
            return true;

        bool leftRes = valid(node->left, lb, node->val);
        bool rightRes = valid(node->right, node->val, ub);
        int currRes = false;

        if (node->val > lb && node->val < ub)
            currRes = true;
        
        return leftRes && rightRes && currRes;
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