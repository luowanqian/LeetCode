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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (NULL == headA || NULL == headB)
            return NULL;
        if (headA == headB)
            return headA;

        ListNode *prevA, *prevB;
        ListNode *currA, *currB;
        ListNode *posA, *posB;

        prevA = prevB = NULL;
        posA = currA = headA;
        posB = currB = headB;
        while ((currA != NULL) || (currB != NULL)) {
            if (currA != NULL) {
                prevA = currA;
                currA = currA->next;
            } else {
                posB = posB->next;
            }
            if (currB != NULL) {
                prevB = currB;
                currB = currB->next;
            } else {
                posA = posA->next;
            }
        }
        // have intersection
        if (prevA == prevB) {
            while (posA != posB) {
                posA = posA->next;
                posB = posB->next;
            }
            return posA;
        }

        return NULL;
    }
};

int main()
{
    ListNode *node1 = create_list_node(0);
    ListNode *node2 = create_list_node(9);
    ListNode *node3 = create_list_node(1);
    ListNode *node4 = create_list_node(3);
    ListNode *node5 = create_list_node(2);
    ListNode *node6 = create_list_node(4);
    connect_list_nodes(node1, node2);
    connect_list_nodes(node2, node3);
    connect_list_nodes(node3, node5);
    connect_list_nodes(node4, node5);
    connect_list_nodes(node5, node6);

    print_list(node1);
    print_list(node4);

    Solution solu;
    ListNode *node = solu.getIntersectionNode(node1, node4);
    if (NULL == node) {
        cout << "No intersection" << endl;
    } else {
        cout << "Intersection node: " << node->val << endl;
    }

    return 0;
}