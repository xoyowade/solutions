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
    TreeNode* rleaf(TreeNode *root) {
        if (!root) {
            return NULL;
        }
        while (root->right) {
            root = root->right;
        }
        return root;
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return;
        }
        
        if (!root->left && !root->right) {
            return;
        }
            
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *rleaf_of_lsub = rleaf(root->left);
        if (rleaf_of_lsub) {
            rleaf_of_lsub->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
