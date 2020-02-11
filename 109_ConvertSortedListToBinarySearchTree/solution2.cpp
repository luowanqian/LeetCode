#include "List.h"
#include "BinaryTree.h"
#include <iostream>
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (NULL == head)
            return NULL;
        if (NULL == head->next)
            return new TreeNode(head->val);

        ListNode *fast, *slow, *pre;

        fast = head->next;
        slow = head;
        pre = head;
        while (NULL != fast) {
            pre = slow;
            slow = slow->next;
            if (NULL != fast->next)
                fast = fast->next->next;
            else
                fast = NULL;
        }
        pre->next = NULL;

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

int main()
{
    ListNode *node1 = create_list_node(0);
    ListNode *node2 = create_list_node(1);
    ListNode *node3 = create_list_node(2);
    ListNode *node4 = create_list_node(3);
    ListNode *node5 = create_list_node(4);
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

