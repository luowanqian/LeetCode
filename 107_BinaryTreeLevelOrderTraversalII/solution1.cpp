#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> level;
        queue<TreeNode*> node_queue;
        TreeNode *node;
        int next_level;
        int to_travel;

        if (root == NULL)
            return ret;

        next_level = 0;
        to_travel = 1;
        node_queue.push(root);
        while (!node_queue.empty()) {
            node = node_queue.front();
            level.push_back(node->val);

            if (node->left != NULL) {
                node_queue.push(node->left);
                next_level++;
            }
            if (node->right != NULL) {
                node_queue.push(node->right);
                next_level++;
            }

            node_queue.pop();
            to_travel--;
            if (to_travel == 0) {
                to_travel = next_level;
                next_level = 0;
                ret.push_back(level);
                level.clear();
            }
        }

        reverse(ret.begin(), ret.end());

        return ret;
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
    //print_tree(node1);

    Solution solu;
    vector<vector<int>> traversal = solu.levelOrderBottom(node1);

    for (int i=0; i<traversal.size(); i++) {
        for (int j=0; j<traversal[i].size(); j++) {
            cout << traversal[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
