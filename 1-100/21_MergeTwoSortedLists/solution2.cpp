#include <iostream>
#include "List.h"

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
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *head, *current;
        ListNode *current1 = l1;
        ListNode *current2 = l2;

        if (l1->val > l2->val) {
            head = current2;
            current2 = current2->next;
        } else {
            head = current1;
            current1 = current1->next;
        }
        current = head;
        head->next = nullptr;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->val > current2->val) {
                current->next = current2;
                current2 = current2->next;
            } else {
                current->next = current1;
                current1 = current1->next;
            }
            current = current->next;
        }
        if (current1 == nullptr) {
            current->next = current2;
        } else {
            current->next = current1;
        }
        return head;
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