#include <iostream>
#include "List.h"
using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode *current_node, *next_node, *tmp_node;
        current_node = head;
        next_node = head->next;
        head->next = NULL;
        while (next_node != NULL) {
            tmp_node = next_node->next;
            next_node->next = current_node;
            current_node = next_node;
            next_node = tmp_node;
        }

        return current_node;
    }
};

int main()
{
    ListNode *node1 = create_list_node(1);
    ListNode *node2 = create_list_node(2);
    ListNode *node3 = create_list_node(3);
    ListNode *node4 = create_list_node(4);
    ListNode *node5 = create_list_node(5);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node5);
    print_list(node1);

    Solution solu;
    ListNode *reverse = solu.reverseList(node1);
    print_list(reverse);

    return 0;
}
