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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        ListNode *pos1, *pos2, *prev;
        int step;

        prev = NULL;
        pos1 = pos2 = head;
        step = 0;
        while (pos2 != NULL) {
            pos2 = pos2->next;
            step += 1;
            if (step > n) {
                prev = pos1;
                pos1 = pos1->next;
            }
        }
        if (prev == NULL)
            head = head->next;
        else
            prev->next = pos1->next;

        return head;
    }
};

int main()
{
    ListNode* node1 = create_list_node(1);
    ListNode* node2 = create_list_node(2);
    ListNode* node3 = create_list_node(3);
    ListNode* node4 = create_list_node(4);
    ListNode* node5 = create_list_node(5);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node5);
    print_list(node1);

    Solution solu;
    int n = 2;
    print_list(solu.removeNthFromEnd(node1, n));

    return 0;
}