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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        int sum = targetSum - root->val;
        int leftRes = hasPathSum(root->left, sum);
        int rightRes = hasPathSum(root->right, sum);
        int curRes = false;
        if (sum == 0 && root->left == nullptr && root->right == nullptr)
            curRes = true;
        return curRes || leftRes || rightRes;
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
    cout << solu.hasPathSum(node1, sum) << endl;

    return 0;
}