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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        TreeNode* node = new TreeNode(val);
        TreeNode* parent = nullptr;
        TreeNode* curr = root;
        while (curr != nullptr) {
            parent = curr;
            if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (parent->val > val)
            parent->left = node;
        else
            parent->right = node;
        return root;
    }
};

int main()
{
    return 0;
}