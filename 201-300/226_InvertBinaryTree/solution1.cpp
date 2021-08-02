#include "BinaryTree.h"
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};

int main()
{
    TreeNode* node1 = create_tree_node(2);
    TreeNode* node2 = create_tree_node(1);
    TreeNode* node3 = create_tree_node(3);
    connect_tree_nodes(node1, node2, node3);
    print_tree(node1);

    cout << "=================" << endl;
    cout << endl;

    Solution solu;
    TreeNode* root = solu.invertTree(node1);
    print_tree(root);

    return 0;
}
