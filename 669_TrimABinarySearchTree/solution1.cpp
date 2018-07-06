#include <iostream>
#include "BinaryTree.h"
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return NULL;

        return trimTree(root, NULL, L, R);
    }

    TreeNode* trimTree(TreeNode* node, TreeNode* root, int L, int R) {
        if (node == NULL) {
            return NULL;
        } else {
            if (node->val < L)
                return trimTree(node->right, root, L, R);
            else if (node->val > R)
                return trimTree(node->left, root, L, R);

            TreeNode *left, *right;
            left = node->left;
            right = node->right;

            if (root == NULL) {
                root = node;
                root->left = NULL;
                root->right = NULL;
            } else {
                TreeNode *pre, *current;
                pre = NULL;
                current = root;
                while (current != NULL) {
                    pre = current;
                    if (node->val < current->val)
                        current = current->left;
                    else
                        current = current->right;
                }
                if (node->val < pre->val)
                    pre->left = node;
                else
                    pre->right = node;
                node->left = NULL;
                node->right = NULL;
            }

            trimTree(left, root, L, R);
            trimTree(right, root, L, R);

            return root;
        }
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(3);
    TreeNode *node2 = create_tree_node(0);
    TreeNode *node3 = create_tree_node(4);
    TreeNode *node4 = create_tree_node(2);
    TreeNode *node5 = create_tree_node(1);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, NULL, node4);
    connect_tree_nodes(node4, node5, NULL);
    //print_tree(node1);

    Solution solu;
    TreeNode *root = solu.trimBST(node1, 1, 3);
    print_tree(root);

    return 0;
}
