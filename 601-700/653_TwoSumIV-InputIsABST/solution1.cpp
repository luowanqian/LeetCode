#include "BinaryTree.h"
#include <unordered_set>
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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)
            return false;
        unordered_set<int> nums;
        return find(root, k, nums);
    }

    bool find(TreeNode* root, int k, unordered_set<int>& nums) {
        if (root == nullptr)
            return false;
        if (nums.count(root->val))
            return true;
        int diff = k - root->val;
        nums.insert(diff);
        int leftRes = find(root->left, k, nums);
        int rightRes = find(root->right, k, nums);
        return leftRes || rightRes;
    }
};

int main()
{
    return 0;
}