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
    int solve(TreeNode* root, int* d){
        if (!root) {
            return -1;
        }

        int l = 1 + solve(root->left, d);
        int r = 1 + solve(root->right, d);

        if (l + r > *d) {
            *d = l + r;
        }
        
        int h = max(l, r);
        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        solve(root, &d);

        return d;
    }
};
