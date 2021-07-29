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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode *prev, *cur;
        prev = nullptr;
        cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                if (prev == nullptr) {
                    head = cur->next;
                    // delete cur;
                    cur = head;
                } else {
                    prev->next = cur->next;
                    // delete cur;
                    cur = prev->next;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *node1 = create_list_node(1);
    ListNode *node2 = create_list_node(2);
    ListNode *node3 = create_list_node(6);
    ListNode *node4 = create_list_node(3);
    ListNode *node5 = create_list_node(4);
    ListNode *node6 = create_list_node(5);
    ListNode *node7 = create_list_node(6);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node5);
    connect_list_nodes(node5, node6);
    connect_list_nodes(node6, node7);
    print_list(node1);

    int val = 6;

    Solution solu;
    ListNode *node = solu.removeElements(node1, val);
    print_list(node);

    return 0;
}