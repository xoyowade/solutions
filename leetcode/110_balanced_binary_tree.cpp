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
    int depth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1+max(depth(root->left), depth(root->right));
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return true;
        }
        return abs(depth(root->left)-depth(root->right)) <= 1 && 
                isBalanced(root->left) && isBalanced(root->right);
    }
};
