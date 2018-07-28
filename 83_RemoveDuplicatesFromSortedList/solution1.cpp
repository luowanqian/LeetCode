#include "List.h"
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre, *cur;
        int dup;

        if (head == NULL)
            return NULL;

        pre = head;
        cur = head->next;
        dup = head->val;
        while (cur != NULL) {
            if (dup == cur->val) {
                pre->next = cur->next;
            } else {
                pre = cur;
                dup = cur->val;
            }
            cur = cur->next;
        }

        return head;
    }
};

int main()
{
    ListNode *node1 = create_list_node(1);
    ListNode *node2 = create_list_node(1);
    ListNode *node3 = create_list_node(2);
    ListNode *node4 = create_list_node(3);
    ListNode *node5 = create_list_node(3);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node5);

    print_list(node1);

    Solution solu;
    ListNode *root = solu.deleteDuplicates(node1);

    print_list(root);

    return 0;
}
