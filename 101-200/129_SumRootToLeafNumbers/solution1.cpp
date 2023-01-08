/*
 * LeetCode 129. Sum Root to Leaf Numbers
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
    int answer = 0;
public:
    int sumNumbers(TreeNode* root) {
        travel(root, 0);
        return answer;
    }

    void travel(TreeNode* root, int val) {
        if (!root) {
            return;
        }

        int newVal = val * 10 + root->val;

        // leaf node
        if (!root->left && !root->right) {
            answer += newVal;
        }

        travel(root->left, newVal);
        travel(root->right, newVal);
    }
};

int main()
{
    Solution sol;

    TreeNode *node11 = create_tree_node(4);
    TreeNode *node12 = create_tree_node(9);
    TreeNode *node13 = create_tree_node(0);
    TreeNode *node14 = create_tree_node(5);
    TreeNode *node15 = create_tree_node(1);
    connect_tree_nodes(node11, node12, node13);
    connect_tree_nodes(node12, node14, node15);
    print_tree(node11);
    cout << sol.sumNumbers(node11) << endl;;

    return 0;
}