/*
 * 2020-08-19
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        preorder(root, values);

        return values;
    }

    void preorder(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        } else {
            values.push_back(root->val);
            preorder(root->left, values);
            preorder(root->right, values);
        }
    }
};

int main()
{
    return 0;
}