/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return false;
        }
        int remain = sum - root->val;
        if (remain == 0 && !root->left && !root->right) {
            return true;
        }
        return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
    }
};
