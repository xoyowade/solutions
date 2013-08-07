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
    bool isValidBST(TreeNode *root, int minimum, int maximum) {
        if (!root) {
            return true;
        }
        if (root->val < minimum || root->val > maximum) {
            return false;
        }
        return isValidBST(root->left, minimum, root->val-1) &&
            isValidBST(root->right, root->val+1, maximum);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
