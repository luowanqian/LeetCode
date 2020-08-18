#ifndef SOLUTIONS_BINARYTREE_H
#define SOLUTIONS_BINARYTREE_H

#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

typedef struct TreeNode Node;

TreeNode* create_tree_node(int value);
void connect_tree_nodes(TreeNode *parent, TreeNode *left, TreeNode *right);
void print_tree_node(const TreeNode *node);
void print_tree(const TreeNode *root);

#endif //SOLUTIONS_BINARYTREE_H
