#include "List.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* create_list_node(int value)
{
    ListNode *node = new ListNode;
    node->val = value;
    node->next = NULL;

    return node;
}

void connect_list_nodes(ListNode *pre_node, ListNode *next_node)
{
    if (pre_node == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pre_node->next = next_node;
}

void print_list(ListNode *head)
{
    printf("print_list starts.\n");

    ListNode *node = head;
    while (node != NULL)
    {
        printf("%d\t", node->val);
        node = node->next;
    }

    printf("\nprint_list ends.\n");
}
