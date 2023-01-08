/*
 * LeetCode 236. Lowest Common Ancestor of a Binary Tree
 * History:
 *  2023.1.8 : first version
 */

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
private:
    TreeNode* answer = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travel(root, p, q);
        return answer;
    }

    bool travel(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }

        bool leftAns = travel(root->left, p, q);
        bool rightAns = travel(root->right, p, q);

        bool rootAns = false;
        if (root == p || root == q) {
            rootAns = true;
            if (leftAns || rightAns) {
                answer = root;
            }
        } else if (leftAns && rightAns) {
            answer = root;
        }

        return rootAns || leftAns || rightAns;
    }
};

int main()
{
    Solution sol;

    TreeNode *node11 = create_tree_node(3);
    TreeNode *node12 = create_tree_node(5);
    TreeNode *node13 = create_tree_node(1);
    connect_tree_nodes(node11, node12, node13);
    TreeNode *node14 = create_tree_node(6);
    TreeNode *node15 = create_tree_node(2);
    connect_tree_nodes(node12, node14, node15);
    TreeNode *node16 = create_tree_node(0);
    TreeNode *node17 = create_tree_node(8);
    connect_tree_nodes(node13, node16, node17);
    TreeNode *node18 = create_tree_node(7);
    TreeNode *node19 = create_tree_node(4);
    connect_tree_nodes(node15, node18, node19);
    print_tree(node11);

    cout << "=====================" << endl;

    // The LCA of nodes 5 and 0 is 3
    cout << "The LCA of nodes 5 and 0 is: " << endl;
    TreeNode *ans1 = sol.lowestCommonAncestor(node11, node12, node16);
    print_tree_node(ans1);
    cout << endl;

    return 0;
}