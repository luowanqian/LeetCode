/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include "../Utilities/List.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *list, *pre_node, *node;
        int value;
        bool carray;

        carray = false;
        list = NULL;
        pre_node = list;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                value = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != NULL) {
                value = l1->val;
                l1 = l1->next;
            } else {
                value = l2->val;
                l2 = l2->next;
            }

            value = carray ? value + 1 : value;
            if (value >= 10)
                carray = true;
            else
                carray = false;
            value = value % 10;

            node = create_list_node(value);
            if (pre_node == NULL)
                list = node;
            else
                connect_list_nodes(pre_node, node);
            pre_node = node;
        }
        if (carray) {
            node = create_list_node(1);
            connect_list_nodes(pre_node, node);
        }

        return list;
    }
};

int main()
{
    ListNode *node11 = create_list_node(2);
    ListNode *node12 = create_list_node(4);
    ListNode *node13 = create_list_node(3);
    connect_list_nodes(node11, node12);
    connect_list_nodes(node12, node13);

    cout << "List 1: " << endl;
    print_list(node11);

    ListNode *node21 = create_list_node(5);
    ListNode *node22 = create_list_node(6);
    ListNode *node23 = create_list_node(4);
    connect_list_nodes(node21, node22);
    connect_list_nodes(node22, node23);

    cout << endl;
    cout << "List 2: " << endl;
    print_list(node21);

    Solution solu;
    ListNode *list = solu.addTwoNumbers(node11, node21);

    cout << endl;
    cout << "Result list: " << endl;
    print_list(list);

    return 0;
}
