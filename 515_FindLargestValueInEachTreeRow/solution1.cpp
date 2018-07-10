#include <queue>
#include <iostream>
#include <vector>
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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL)
            return vector<int>();

        vector<int> ret;
        queue<TreeNode*> nodes;
        TreeNode *current_node;
        int current_level, next_level;
        int largest;

        current_level = 1;
        next_level = 0;
        largest = root->val;
        nodes.push(root);
        while (!nodes.empty()) {
            current_node = nodes.front();

            if (current_node->left != NULL) {
                nodes.push(current_node->left);
                next_level++;
            }

            if (current_node->right != NULL) {
                nodes.push(current_node->right);
                next_level++;
            }

            if (current_node->val > largest)
                largest = current_node->val;

            nodes.pop();
            current_level--;
            if (current_level == 0) {
                current_level = next_level;
                next_level = 0;
                ret.push_back(largest);
                if (!nodes.empty())
                    largest = nodes.front()->val;
            }
        }

        return ret;
    }
};

int main()
{
    TreeNode *node1 = create_tree_node(1);
    TreeNode *node2 = create_tree_node(3);
    TreeNode *node3 = create_tree_node(2);
    TreeNode *node4 = create_tree_node(5);
    TreeNode *node5 = create_tree_node(3);
    TreeNode *node6 = create_tree_node(9);
    connect_tree_nodes(node1, node2, node3);
    connect_tree_nodes(node2, node4, node5);
    connect_tree_nodes(node3, NULL, node6);
    //print_tree(node1);

    Solution solu;
    vector<int> largest = solu.largestValues(node1);
    for (auto it=largest.begin(); it!=largest.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
