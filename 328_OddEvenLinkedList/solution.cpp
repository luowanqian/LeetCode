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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *even, *odd, *node;

        odd = head;
        even = head->next;
        node = head->next;
        while (odd != NULL && odd->next != NULL
               && even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = node;

        return head;
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
    ListNode *node = solu.oddEvenList(node1);
    print_list(node);

    return 0;
}
