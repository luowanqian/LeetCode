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

        ListNode *point1, *point2, *prev, *ret;
        int steps;

        steps = 0;
        prev = NULL;
        point1 = point2 = head;
        while (point2 != NULL) {
            point2 = point2->next;
            steps++;
            if (steps >= n)
                break;
        }
        if (steps < n)
            return head;

        while (point2 != NULL) {
            prev = point1;
            point1 = point1->next;
            point2 = point2->next;
        }

        if (prev != NULL) {
            prev->next = point1->next;
            ret = head;
        } else {
            ret = head->next;
        }
        delete point1;

        return ret;
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