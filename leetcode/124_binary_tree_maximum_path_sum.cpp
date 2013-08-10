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
    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        int local = root->val;
        local += (l>0) ? l : 0;
        local += (r>0) ? r : 0;
        
        max_sum = max(max_sum, local);
        
        return max(root->val, max(root->val+l, root->val+r));
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        max_sum = INT_MIN;
        
        dfs(root);
        
        return max_sum;
    }
    
    int max_sum;
};
