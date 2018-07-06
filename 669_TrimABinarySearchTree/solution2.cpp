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
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (root == NULL)
            return NULL;

        if (root->val < L) {
            return trimBST(root->right, L, R);
        } else if (root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        } else {
            return trimBST(root->left, L, R);
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
