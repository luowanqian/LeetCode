#include <iostream>
#include "List.h"

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        ListNode *node1, *node2;
        ListNode *root, *node;

        root = NULL;
        node = NULL;
        node1 = l1;
        node2 = l2;
        while (node1 != NULL && node2 != NULL) {
            if (root == NULL) {
                if (node1->val > node2->val) {
                    root = node2;
                    node2 = node2->next;
                } else {
                    root = node1;
                    node1 = node1->next;
                }
                node = root;
                node->next = NULL;
            } else {
                if (node1->val > node2->val) {
                    node->next = node2;
                    node2 = node2->next;
                } else {
                    node->next = node1;
                    node1 = node1->next;
                }
                node = node->next;
                node->next = NULL;
            }
        }
        if (node1 != NULL && node != NULL) {
            node->next = node1;
        } else if (node2 != NULL && node != NULL) {
            node->next = node2;
        }

        return root;
    }
};

int main()
{
    ListNode *node1 = create_list_node(1);
    ListNode *node2 = create_list_node(2);
    ListNode *node3 = create_list_node(4);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    print_list(node1);

    ListNode *node4 = create_list_node(1);
    ListNode *node5 = create_list_node(3);
    ListNode *node6 = create_list_node(4);
    connect_list_nodes(node4, node5);
    connect_list_nodes(node5, node6);
    print_list(node4);

    Solution solu;
    ListNode *node = solu.mergeTwoLists(node1, node4);
    print_list(node);

    return 0;
}
