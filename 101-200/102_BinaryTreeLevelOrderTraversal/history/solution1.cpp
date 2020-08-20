/*
 * 2020-08-20
 */

#include "BinaryTree.h"
#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> val;
        int curr_level, next_level;
        TreeNode* node;
        queue<TreeNode*> node_queue;

        if (root == NULL)
            return res;
        node_queue.push(root);
        curr_level = 1;
        next_level = 0;
        while (!node_queue.empty()) {
            node = node_queue.front();
            if (NULL != node->left) {
                node_queue.push(node->left);
                next_level++;
            }
            if (NULL != node->right) {
                node_queue.push(node->right);
                next_level++;
            }

            node_queue.pop();
            curr_level--;
            val.push_back(node->val);
            if (curr_level <= 0) {
                res.push_back(val);
                val.clear();
                curr_level = next_level;
                next_level = 0;
            }
        }

        return res;
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(3);
    TreeNode *node2 = create_tree_node(9);
    TreeNode *node3 = create_tree_node(20);
    TreeNode *node4 = create_tree_node(15);
    TreeNode *node5 = create_tree_node(7);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node3, node4, node5);
    print_tree(node1);

    Solution solu;
    vector<vector<int>> ret = solu.levelOrder(node1);
    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}