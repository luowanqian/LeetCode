#include "BinaryTree2.h"
#include <cstdio>

TreeNode* create_tree_node(int value)
{
    TreeNode *node = new TreeNode(value);
    node->left = NULL;
    node->right = NULL;

    return node;
}

void connect_tree_nodes(TreeNode *parent, TreeNode *left, TreeNode *right)
{
    if (parent != NULL) {
        parent->left = left;
        parent->right = right;
    }
}

void print_tree_node(const TreeNode *node)
{
    if (node != NULL) {
        printf("value of this node is: %d\n", node->val);

        if (node->left != NULL)
            printf("value of its left child is: %d.\n", node->left->val);
        else
            printf("left child is NULL.\n");

        if (node->right != NULL)
            printf("value of its right child is: %d.\n", node->right->val);
        else
            printf("right child is NULL.\n");
    } else {
        printf("this node is NULL.\n");
    }

    printf("\n");
}

void print_tree(const TreeNode *root)
{
    print_tree_node(root);

    if (root != NULL) {
        if (root->left != NULL)
            print_tree(root->left);

        if (root->right != NULL)
            print_tree(root->right);
    }
}
