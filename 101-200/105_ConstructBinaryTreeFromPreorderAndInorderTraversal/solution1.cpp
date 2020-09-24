/*
 * 2020-09-24
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
private:
    int m_idx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty())
            return NULL;
        m_idx = 0;
        return construct(preorder, inorder, 0, inorder.size());
    }

    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start >= end)
            return NULL;

        int root_val = preorder[m_idx];
        int root_idx = -1;
        TreeNode* root = new TreeNode(root_val);

        for (int i=start; i<end; i++) {
            if (inorder[i] == root_val) {
                root_idx = i;
                break;
            }
        }
        if (start < root_idx) {
            m_idx++;
            root->left = construct(preorder, inorder, start, root_idx);
        } else {
            root->left = NULL;
        }
        if (root_idx + 1 < end) {
            m_idx++;
            root->right = construct(preorder, inorder, root_idx + 1, end);
        } else {
            root->right = NULL;
        }
        return root;
    }
};

int main()
{
    vector<int> preorder = {3, 1, 2, 4};
    vector<int> inorder = {1, 2, 3, 4};
    Solution solu;
    TreeNode* root = solu.buildTree(preorder, inorder);
    print_tree(root);

    return 0;
}