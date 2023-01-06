/*
 * History:
 *  2022.1.6 : first version
 */

#include "List.h"
#include <vector>
#include <iostream>
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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }

        ListNode *slowNode, *fastNode, *prevNode, *nextNode;
        slowNode = head;
        fastNode = head->next;
        prevNode = nullptr;
        nextNode = head->next;
        while (fastNode != nullptr && fastNode->next != nullptr) {
            fastNode = fastNode->next->next;

            //  slowNode的next指向prevNode
            nextNode = slowNode->next;
            slowNode->next = prevNode;
            prevNode = slowNode;
            slowNode = nextNode;
        }
        if (fastNode == nullptr) {
            // 说明节点数目为奇数
            fastNode = slowNode->next;
            slowNode = prevNode;
        } else {
            // fastNode->next is nullptr, 说明节点数目为偶数
            fastNode = slowNode->next;
            slowNode->next = prevNode;
        }

        while (fastNode != nullptr && slowNode != nullptr) {
            if (fastNode->val != slowNode->val) {
                return false;
            }
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    ListNode *node11 = create_list_node(1);
    ListNode *node12 = create_list_node(2);
    ListNode *node13 = create_list_node(2);
    ListNode *node14 = create_list_node(1);
    connect_list_nodes(node11, node12);
    connect_list_nodes(node12, node13);
    connect_list_nodes(node13, node14);
    cout << "List 1->2->2->1: " << sol.isPalindrome(node11) << endl;

    ListNode *node21 = create_list_node(1);
    ListNode *node22 = create_list_node(2);
    connect_list_nodes(node21, node22);
    cout << "List 1->2: " << sol.isPalindrome(node21) << endl;

    return 0;
}