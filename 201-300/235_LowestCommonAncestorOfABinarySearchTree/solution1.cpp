#include "BinaryTree.h"
#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lb, ub;
        if (p->val > q->val) {
            lb = q->val;
            ub = p->val;   
        } else {
            lb = p->val;
            ub = q->val;
        }
        return search(root, lb, ub);
    }

    TreeNode* search(TreeNode* root, int lb, int ub) {
        if (root == nullptr)
            return nullptr;
        if (root->val >= lb && root->val <= ub)
            return root;
        TreeNode* left = search(root->left, lb, ub);
        if (left != nullptr)
            return left;
        TreeNode* right = search(root->right, lb, ub);
        return right;
    }
};

int main()
{
    return 0;
}