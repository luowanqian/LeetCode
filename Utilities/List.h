#ifndef SOLUTIONS_LIST_H
#define SOLUTIONS_LIST_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list_node(int value);
void connect_list_nodes(ListNode *pre_node, ListNode *next_node);
void print_list_node(ListNode *node);
void print_list(ListNode *head);

#endif //SOLUTIONS_LIST_H
