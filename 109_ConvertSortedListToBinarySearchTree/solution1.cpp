#include "List.h"
#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

    TreeNode* sortedListToBST(ListNode* head) {
        if (NULL == head)
            return NULL;
        if (NULL == head->next)
            return new TreeNode(head->val);

        vector<int> nums;
        ListNode *pointer = head;
        while (NULL != pointer) {
            nums.push_back(pointer->val);
            pointer = pointer->next;
        }

        return construct_bst(nums, 0, nums.size()-1);
    }
};

int main()
{
    ListNode *node1 = create_list_node(-10);
    ListNode *node2 = create_list_node(-3);
    ListNode *node3 = create_list_node(0);
    ListNode *node4 = create_list_node(5);
    ListNode *node5 = create_list_node(9);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node5);
    print_list(node1);

    Solution solu;
    TreeNode *root = solu.sortedListToBST(node1);
    print_tree(root);

    return 0;
}