/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "BinaryTree.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } else if (t1 == NULL && t2 != NULL) {
            return t2;
        } else if (t1 != NULL && t2 == NULL) {
            return t1;
        } else {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);

            return t1;
        }
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(1);
    TreeNode *node2 = create_tree_node(3);
    TreeNode *node3 = create_tree_node(2);
    TreeNode *node4 = create_tree_node(5);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, node4, NULL);
    //print_tree(node1);

    TreeNode *node5 = create_tree_node(2);
    TreeNode *node6 = create_tree_node(1);
    TreeNode *node7 = create_tree_node(3);
    TreeNode *node8 = create_tree_node(4);
    TreeNode *node9 = create_tree_node(7);
    connect_tree_nodes(node5, node6, node7);
    connect_tree_nodes(node6, NULL, node8);
    connect_tree_nodes(node7, NULL, node9);
    //print_tree(node5);

    Solution solu;
    TreeNode *root = solu.mergeTrees(node1, node5);
    print_tree(root);

    return 0;
}