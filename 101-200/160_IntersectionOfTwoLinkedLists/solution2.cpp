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
        if (headA == NULL)
            return NULL;
        if (headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;
        int lenA;
        int lenB;
        int steps;
        ListNode* posA;
        ListNode* posB;

        posA = headA;
        posB = headB;
        lenA = lenB = 0;
        while (posA != NULL || posB != NULL) {
            if (posA != NULL) {
                posA = posA->next;
                lenA++;
            }
            if (posB != NULL) {
                posB = posB->next;
                lenB++;
            }
        }
        posA = headA;
        posB = headB;
        if (lenA > lenB) {
            steps = lenA - lenB;
            int n = 0;
            while (posA != NULL && n < steps) {
                posA = posA->next;
                n++;
            }
        } else if (lenB > lenA) {
            steps = lenB - lenA;
            int n = 0;
            while (posB != NULL && n < steps) {
                posB = posB->next;
                n++;
            }
        }
        while (posA != NULL && posB != NULL) {
            if (posA == posB)
                return posA;
            posA = posA->next;
            posB = posB->next;
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