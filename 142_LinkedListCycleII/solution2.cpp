#include "List.h"
#include <set>
#include <iostream>
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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> node_set;
        ListNode *node;

        node = head;
        while (node != NULL) {
            if (node_set.find(node) == node_set.end())
                node_set.insert(node);
            else
                return node;
            node = node->next;
        }

        return node;
    }
};


int main()
{
    ListNode *node1 = create_list_node(3);
    ListNode *node2 = create_list_node(2);
    ListNode *node3 = create_list_node(0);
    ListNode *node4 = create_list_node(-4);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node4);
    connect_list_nodes(node4, node2);

    Solution solu;
    ListNode *cycle = solu.detectCycle(node1);
    if (NULL != cycle) {
        cout << "Cycle start at node: " << cycle->val << endl;
    } else {
        cout << "NO cycle" << endl;
    }

    return 0;
}
