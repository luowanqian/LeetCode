#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTree.h"
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
        if (root == nullptr)
            return vector<vector<int>>();

        queue<TreeNode*> trace;
        trace.push(root);
        int numNodesInCurLevel = 1;
        int numNodesInNextLevel = 0;
        vector<vector<int>> res;
        vector<int> nodesInOneLevel;
        while (!trace.empty()) {
            TreeNode* node = trace.front();
            nodesInOneLevel.push_back(node->val);
            trace.pop();
            numNodesInCurLevel--;
            if (node->left != nullptr) {
                trace.push(node->left);
                numNodesInNextLevel++;
            }
            if (node->right != nullptr) {
                numNodesInNextLevel++;
                trace.push(node->right);
            }
            if (numNodesInCurLevel <= 0) {
                numNodesInCurLevel = numNodesInNextLevel;
                numNodesInNextLevel = 0;
                res.push_back(nodesInOneLevel);
                nodesInOneLevel.clear();
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
    connect_tree_nodes(node2, node4, node5);
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