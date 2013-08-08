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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q;
        q.push(root);
        
        int count = q.size();
        vector<vector<int> > res;
        vector<int> level;
        while (!q.empty()) {
            if (count == 0) {
                // new level
                res.push_back(level);
                level.clear();
                count = q.size();
            }
            count--;
            TreeNode *n = q.front();
            q.pop();
            if (n) {
                level.push_back(n->val);
                q.push(n->left);
                q.push(n->right);
            }
        }
        
        return res;
    }
};
