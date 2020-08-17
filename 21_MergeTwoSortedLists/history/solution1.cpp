/*
 * 2020-08-16
 */

#include <iostream>
#include "List.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        ListNode *head, *curr;
        ListNode *curr1;
        ListNode *curr2;

        if (l1->val < l2->val) {
            head = l1;
            curr = l1;
            curr1 = l1->next;
            curr2 = l2;
        } else {
            head = l2;
            curr = l2;
            curr1 = l1;
            curr2 = l2->next;
        }

        while (curr1 != NULL && curr2 != NULL) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        if (curr1 == NULL)
            curr->next = curr2;
        else if (curr2 == NULL)
            curr->next = curr1;
        else
            curr->next = NULL;

        return head;
    }
};

int main()
{
    ListNode *node1_1 = create_list_node(1);
    ListNode *node1_2 = create_list_node(2);
    ListNode *node1_3 = create_list_node(4);
    connect_list_nodes(node1_1, node1_2);
    connect_list_nodes(node1_2, node1_3);

    ListNode *node2_1 = create_list_node(1);
    ListNode *node2_2 = create_list_node(3);
    ListNode *node2_3 = create_list_node(4);
    connect_list_nodes(node2_1, node2_2);
    connect_list_nodes(node2_2, node2_3);

    print_list(node1_1);
    print_list(node2_1);

    Solution solu;
    ListNode *list = solu.mergeTwoLists(node1_1, node2_1);
    print_list(list);

    return 0;
}