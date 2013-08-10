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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return 0;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if (left == 0 && right == 0) {
            return 1;
        }
        if (left == 0 || right == 0) {
            return max(left, right)+1;
        }
        
        return min(left, right)+1;
    }
};
