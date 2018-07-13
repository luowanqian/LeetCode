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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p != NULL && q == NULL){
            return false;
        } else if (p == NULL && q != NULL){
            return false;
        } else {
            bool center = p->val == q->val;
            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);

            return center && left && right;
        }
    }
};

int main()
{
    TreeNode *node11 = create_tree_node(1);
    TreeNode *node12 = create_tree_node(2);
    TreeNode *node13 = create_tree_node(1);
    connect_tree_nodes(node11, node12, node13);
    print_tree(node11);

    TreeNode *node21 = create_tree_node(1);
    TreeNode *node22 = create_tree_node(2);
    TreeNode *node23 = create_tree_node(1);
    connect_tree_nodes(node21, node23, node22);
    print_tree(node21);

    Solution solu;
    cout << "Tree same: " << solu.isSameTree(node11, node21);

    return 0;
}
