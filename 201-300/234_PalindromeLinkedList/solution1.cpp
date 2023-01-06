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

        vector<int> arr;
        ListNode *pos = head;
        while (pos != nullptr) {
            arr.push_back(pos->val);
            pos = pos->next;
        }

        int res = true;
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            if (arr[i] != arr[j]) {
                res = false;
                break;
            }
            i++; j--;
        }
        return res;
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