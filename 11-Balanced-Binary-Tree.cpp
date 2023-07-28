#include <cmath>

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
    int dfs(TreeNode* node, bool & isBalanced) {
        if (!node) {
            return 0;
        }

        int left_depth = dfs(node->left, isBalanced);
        int right_depth = dfs(node->right, isBalanced);

        if (abs(left_depth - right_depth) > 1) {
            isBalanced = false;
        }

        return max(left_depth, right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;

        dfs(root, isBalanced);

        return isBalanced;
    }
};
