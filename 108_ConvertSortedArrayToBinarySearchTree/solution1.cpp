#include <iostream>
#include <vector>
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
    TreeNode* construct_bst(vector<int>& nums, int left, int right) {

        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = construct_bst(nums, left, mid-1);
        node->right = construct_bst(nums, mid+1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;

        return construct_bst(nums, 0, nums.size()-1);
    }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solu;
    TreeNode *node = solu.sortedArrayToBST(nums);
    print_tree(node);

    return 0;
}
