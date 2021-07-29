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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        if (head->next == head)
            return true;
        if (head->next == NULL)
            return false;

        ListNode *node1, *node2;

        node1 = head;
        node2 = head->next->next;
        while (node2 != NULL && node1 != node2) {
            node1 = node1->next;
            if (node2->next == NULL)
                return false;
            node2 = node2->next->next;
        }
        if (node2 != NULL && node1 == node2)
            return true;

        return false;
    }
};

int main()
{
    ListNode *node1 = create_list_node(1);
    ListNode *node2 = create_list_node(2);
    ListNode *node3 = create_list_node(3);
    ListNode *node4 = create_list_node(4);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node2);

    Solution solu;
    cout << solu.hasCycle(node1) << endl;

    return 0;
}

