//
//
//

#include "../Utilities/List.h"
#include <iostream>

class Solution
{
public:
    /*
     * the node is not the last node
     */
    void deleteNode(ListNode* node)
    {
        if (node == NULL)
            return;

        ListNode *next_node = node->next;
        node->val = next_node->val;
        node->next = next_node->next;
        delete next_node;
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
    print_list(node1);

    Solution solu;
    solu.deleteNode(node3);
    print_list(node1);
    return 0;
}