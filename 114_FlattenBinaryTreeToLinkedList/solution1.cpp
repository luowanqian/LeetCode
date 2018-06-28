#include "BinaryTree.h"
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        } else {
            flatten(root->left);
            flatten(root->right);

            TreeNode *node = root->right;
            root->right = root->left;
            root->left = NULL;
            while (root->right)
                root = root->right;
            root->right = node;
        }
    }

};

int main()
{
    TreeNode *node1 = create_tree_node(1);
    TreeNode *node2 = create_tree_node(2);
    TreeNode *node3 = create_tree_node(5);
    TreeNode *node4 = create_tree_node(3);
    TreeNode *node5 = create_tree_node(4);
    TreeNode *node6 = create_tree_node(6);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, node4, node5);
    connect_tree_nodes(node3, NULL, node6);
    //print_tree(node1);

    Solution solu;
    solu.flatten(node1);
    //print_tree(node1);

    TreeNode *node = node1;
    while (node != NULL) {
        cout << node->val << " ";
        node = node->right;
    }

    return 0;
}
