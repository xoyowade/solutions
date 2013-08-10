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
    void findPaths(TreeNode *root, int sum) {
        if (!root) {
            return;
        }
        int remain = sum - root->val;
        if (!root->left && !root->right) {
            if (remain == 0) {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        findPaths(root->left, remain);
        findPaths(root->right, remain);
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        path.clear();
        
        findPaths(root, sum);
        return res;
    }
    
    vector<vector<int> > res;
    vector<int> path;
};
